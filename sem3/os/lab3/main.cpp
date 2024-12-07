#include <Windows.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>

int main(int argc, char* argv[]) {
    if (argc != 5) {
        std::cerr << "Usage: " << argv[0] << " <A> <B> <n> <Max Processes>\n";
        return 1;
    }

    double a = std::stod(argv[1]);
    double b = std::stod(argv[2]);
    int n = std::stoi(argv[3]);
    int maxProcesses = std::stoi(argv[4]);
    
    if (a > b) {
        std::cerr << "Invalid input" << std::endl;
        return 1;
    }

    std::wstring commandLine = L"C:\\Users\\USER\\source\\repos\\university\\sem3\\os\\lab3_tab\\x64\\Debug\\lab3_tab.exe ";

    std::vector<double> timeResults;
    std::vector<double> speedups;

    for (int currentProcessesCount = 1; currentProcessesCount <= maxProcesses; currentProcessesCount++) {
        std::cout << "------------------------------\n" << currentProcessesCount << " processes:\n";

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
        timeResults.push_back(duration.count() * 1000);
    }

    for (int i = 0; i < timeResults.size(); i++) {
        speedups.push_back(timeResults[0] / timeResults[i]);
    }

    auto maxit = std::max_element(speedups.begin(), speedups.end());
    int index = std::distance(speedups.begin(), maxit);
    
    std::cout << "\nMax speedup: " << *maxit << " is reached using " << index + 1 << " processes\n";
    getchar();
}
