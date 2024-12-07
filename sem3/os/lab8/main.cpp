#include <Windows.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <AclAPI.h>

HANDLE file;

void tabulate(double a, double b, int n, int maxProcesses) {
    if (a > b) {
        std::cerr << "Invalid input" << std::endl;
        return;
    }

    std::wstring commandLine = L"C:\\Users\\USER\\source\\repos\\university\\sem3\\os\\lab3_tab\\x64\\Debug\\lab3_tab.exe ";

    if (SetFilePointer(file, 0, NULL, FILE_BEGIN) == INVALID_SET_FILE_POINTER) {
        std::cerr << "Failed to move file pointer. Error: " << GetLastError() << std::endl;
        return;
    }

    if (!SetEndOfFile(file)) {
        std::cerr << "Failed to truncate file. Error: " << GetLastError() << std::endl;
        return;
    }

    std::string output;
    std::vector<double> timeResults;
    std::vector<double> speedups;

    for (int currentProcessesCount = 1; currentProcessesCount <= maxProcesses; currentProcessesCount++) {
        std::cout << "------------------------------\n" << currentProcessesCount << " processes:\n";
        output += "------------------------------\n" + std::to_string(currentProcessesCount) + " processes:\n";

        std::vector<STARTUPINFO> sis(currentProcessesCount);
        std::vector<PROCESS_INFORMATION> pis(currentProcessesCount);

        std::vector<double> start(currentProcessesCount);
        start.push_back(a);

        double division = (b - a) / currentProcessesCount;
        int nDivided = n / currentProcessesCount;
        int remainder = n % currentProcessesCount;

        std::vector<double> end(currentProcessesCount);

        for (int i = 0; i < currentProcessesCount; i++) {
            start[i] = a + i * division;

            end[i] = start[i] + division;
        }

        end[currentProcessesCount - 1] += division / nDivided;

        for (int i = 0; i < currentProcessesCount; i++) {
            int currentDivisions = nDivided + (i == currentProcessesCount - 1 ? remainder : 0);

            std::wstring newCommandLine = commandLine + std::to_wstring(start[i])
                + L" " + std::to_wstring(end[i]) + L" " + std::to_wstring(currentDivisions);

            ZeroMemory(&sis[i], sizeof(sis[i]));
            sis[i].cb = sizeof(sis[i]);
            ZeroMemory(&pis[i], sizeof(pis[i]));

            if (!CreateProcess(
                NULL,
                &newCommandLine[0],
                NULL,
                NULL,
                FALSE,
                CREATE_NO_WINDOW,
                NULL,
                NULL,
                &sis[i],
                &pis[i])) {
                std::cerr << "CreateProcess failed for process " << i << " (" << GetLastError() << ").\n";
            }
        }

        std::vector<HANDLE> handles(currentProcessesCount);

        auto startTime = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < currentProcessesCount; i++) {
            handles[i] = pis[i].hProcess;
        }

        WaitForMultipleObjects(currentProcessesCount, handles.data(), TRUE, INFINITE);

        for (int i = 0; i < currentProcessesCount; i++) {
            CloseHandle(pis[i].hProcess);
            CloseHandle(pis[i].hThread);
        }

        auto endTime = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = endTime - startTime;

        std::cout << "Launched program has finished. Time: " << duration.count() * 1000 << std::endl;
        output += "Launched program has finished. Time: " + std::to_string(duration.count() * 1000) + '\n';

        timeResults.push_back(duration.count() * 1000);
    }

    for (int i = 0; i < timeResults.size(); i++) {
        speedups.push_back(timeResults[0] / timeResults[i]);
    }

    auto maxit = std::max_element(speedups.begin(), speedups.end());
    int index = std::distance(speedups.begin(), maxit);

    std::cout << "\nMax speedup: " << *maxit << " is reached using " << index + 1 << " processes.\n";
    output += "\nMax speedup: " + std::to_string(*maxit) + " is reached using " + std::to_string(index + 1) + " processes.\n";

    DWORD bytesWritten;

    BOOL result = WriteFile(
        file,
        output.c_str(),
        output.length(),
        &bytesWritten,
        NULL
    );
}

void SetCustomSecurityInfoForFile() {
    LPCSTR fileName = "results.txt";
    std::string userName;
    std::string permissionChoice;
    DWORD permissions = 0;

    std::string exitChoice = "";
    while (true) {
        if (exitChoice == "y") {
            break;
        }

        std::cout << "Enter username:\n";
        std::cin >> userName;

        std::cout << "Select permissions for user " << userName << ":\n";
        std::cout << "r - Read\n";
        std::cout << "w - Write\n";
        std::cout << "x - Execute\n";
        std::cout << "Enter combination of permissions (e.g., RW for Read and Write):\n";
        std::cin >> permissionChoice;

        permissions = 0;

        for (char c : permissionChoice) {
            switch (tolower(c)) {
            case 'r':
                permissions |= GENERIC_READ;
                break;
            case 'w':
                permissions |= GENERIC_WRITE;
                break;
            case 'x':
                permissions |= GENERIC_EXECUTE;
                break;
            default:
                std::cerr << "Invalid permission choice: " << c << std::endl;
                continue;
            }
        }

        PACL pOldDACL = nullptr;
        PSECURITY_DESCRIPTOR pSD = nullptr;
        DWORD result = GetNamedSecurityInfoA(
            (LPSTR)fileName,
            SE_FILE_OBJECT,
            DACL_SECURITY_INFORMATION,
            nullptr,
            nullptr,
            &pOldDACL,
            nullptr,
            &pSD
        );

        if (result != ERROR_SUCCESS) {
            std::cerr << "Failed to get existing ACL: " << result << std::endl;
            if (pSD) LocalFree(pSD);
            continue;
        }

        EXPLICIT_ACCESSA ea;
        ZeroMemory(&ea, sizeof(ea));
        ea.grfAccessPermissions = permissions;
        ea.grfAccessMode = SET_ACCESS;
        ea.grfInheritance = NO_INHERITANCE;
        ea.Trustee.TrusteeForm = TRUSTEE_IS_NAME;
        ea.Trustee.TrusteeType = TRUSTEE_IS_USER;
        ea.Trustee.ptstrName = (LPSTR)userName.c_str();

        PACL pNewDACL = nullptr;
        result = SetEntriesInAclA(1, &ea, pOldDACL, &pNewDACL);
        if (result != ERROR_SUCCESS) {
            std::cerr << "Failed to create new ACL: " << result << std::endl;
            if (pSD) LocalFree(pSD);
            if (pNewDACL) LocalFree(pNewDACL);
            continue;
        }

        result = SetNamedSecurityInfoA(
            (LPSTR)fileName,
            SE_FILE_OBJECT,
            DACL_SECURITY_INFORMATION,
            nullptr,
            nullptr,
            pNewDACL,
            nullptr
        );

        if (result == ERROR_SUCCESS) {
            std::cout << "Permissions updated successfully for user: " << userName << "\n";
        } else {
            std::cerr << "Failed to update permissions for user " << userName << ": " << result << std::endl;
        }

        // Cleanup
        if (pSD) LocalFree(pSD);
        if (pNewDACL) LocalFree(pNewDACL);

        std::cout << "Are you done? y/n\n";
        std::cin >> exitChoice;
    }
}

int main() {
    char func = 0;
    double a = 0;
    double b = 0;
    int n = 0;
    int maxProcesses = 0;

    while (func != 'e') {
        std::cout << "Enter the command: ";
        func = getchar();
        
        switch (func) {

        case 'i': {
            std::cout << "t - start tabulation function and write results to file\n"
                << "c - change file access attributes"
                << "e - exit program\n"
                << "s - set custom security for file\n"
                << "i - info/help\n";
        }

        case 'c': {
            char attribute;
            std::cout << "1. n - normal\n2. r - readonly\n3. a - archive\n4. h - hidden\n5. t - temporary\n6. d - directory\n";
            std::cin >> attribute;

            switch (attribute) {
            case 'n':
                SetFileAttributesA("results.txt", FILE_ATTRIBUTE_NORMAL);
                std::cout << "File attributes were changed to normal\n";
                break;

            case 'r':
                SetFileAttributesA("results.txt", FILE_ATTRIBUTE_READONLY);
                std::cout << "File attributes were changed to readonly\n";
                break;

            case 'a':
                SetFileAttributesA("results.txt", FILE_ATTRIBUTE_ARCHIVE);
                std::cout << "File attributes were changed to archive\n";
                break;

            case 'h':
                SetFileAttributesA("results.txt", FILE_ATTRIBUTE_HIDDEN);
                std::cout << "File attributes were changed to hidden\n";
                break;

            case 't':
                SetFileAttributesA("results.txt", FILE_ATTRIBUTE_TEMPORARY);
                std::cout << "File attributes were changed to temporary\n";
                break;

            case 'd':
                SetFileAttributesA("results.txt", FILE_ATTRIBUTE_DIRECTORY);
                std::cout << "File attributes were changed to directory\n";
                break;

            default:
                std::cout << "Invalid input\n";
                break;
            }
            break;
        }
        
        case 's': {
            SetCustomSecurityInfoForFile(); break;
        }

        case 't': {
            file = CreateFileA(
                "results.txt",
                GENERIC_READ | GENERIC_WRITE,   // Desired access (write)
                NULL,                           // Share mode (none)
                NULL,                           // Security attributes
                CREATE_ALWAYS,                  // Creation disposition
                FILE_ATTRIBUTE_NORMAL,          // Flags and attributes
                NULL                            // Template file (not used)
            );

            if (file == INVALID_HANDLE_VALUE) {
                std::cerr << "Failed to create or open file. Error: " << GetLastError() << '\n';
                continue;
            }

            std::cout << "\nEnter the limits: ";
            std::cin >> a >> b >> n >> maxProcesses;
            tabulate(a, b, n, maxProcesses);
            std::cout << '\n';

            CloseHandle(file);
            break;
        }

        case 'e': break;

        default: std::cout << "\nThe command is not recognized (for more info type i). Try again.\n";

        }

        getchar();
    }

    std::cout << "\nEnd of program.\n";
}
