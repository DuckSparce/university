#include "process.h"

#include <string>
#include <windows.h>
#include <iostream>
#include <psapi.h>
#include <tlhelp32.h>

Process::Process(const std::wstring& path) {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Attempt to create the process
    if (!CreateProcessW(
            NULL,               // No module name (use the command line)
            const_cast<LPWSTR>(path.c_str()), // Command line
            NULL,               // Process handle not inheritable
            NULL,               // Thread handle not inheritable
            NULL,               // Set handle inheritance to FALSE
            NORMAL_PRIORITY_CLASS,                  // No creation flags
            NULL,               // Use parent's environment block
            NULL,               // Use parent's starting directory
            &si,                // Pointer to STARTUPINFO structure
            &pi))               // Pointer to PROCESS_INFORMATION structure
    {
        std::cerr << "CreateProcess failed (" << GetLastError() << ").\n";
        return;
    }

    handle_ = pi.hProcess;
    pid_ = pi.dwProcessId;
    name_ = QString(path.substr(path.rfind(L'\\') + 1));
    state_ = QString("Running");

    // priority
    switch (GetPriorityClass(handle_)) {
    case IDLE_PRIORITY_CLASS: priority_ = "Idle"; break;
    case BELOW_NORMAL_PRIORITY_CLASS: priority_ = "Below normal"; break;
    case NORMAL_PRIORITY_CLASS: priority_ = "Normal"; break;
    case ABOVE_NORMAL_PRIORITY_CLASS: priority_ = "Above normal"; break;
    case HIGH_PRIORITY_CLASS: priority_ = "High"; break;
    case REALTIME_PRIORITY_CLASS: priority_ = "Realtime"; break;
    }

    SetProcessAffinityMask(handle_, 0xffff);
    affinity_ = 0xffff;

    // CPU time
    FILETIME creationTime, exitTime, kernelTime, userTime;
    if (GetProcessTimes(handle_, &creationTime, &exitTime, &kernelTime, &userTime)) {
        ULARGE_INTEGER kTime, uTime;
        kTime.LowPart = kernelTime.dwLowDateTime;
        kTime.HighPart = kernelTime.dwHighDateTime;
        uTime.LowPart = userTime.dwLowDateTime;
        uTime.HighPart = userTime.dwHighDateTime;

        cputime_ = kTime.QuadPart / 10000000.0 + uTime.QuadPart / 10000000.0;
    } else {
        std::cerr << "Failed to get process times (" << GetLastError() << ").\n";
    }

    // workingSet and peakWorkingSet
    PROCESS_MEMORY_COUNTERS pmc;
    if (GetProcessMemoryInfo(handle_, &pmc, sizeof(pmc))) {
        workingSet_ = pmc.WorkingSetSize;
        peakWorkingSet_ = pmc.PeakWorkingSetSize;
    } else {
        std::cerr << "Failed to get process memory info (" << GetLastError() << ").\n";
    }
}

HANDLE Process::handle() const {
    return handle_;
}

void Process::setHandle(HANDLE newHandle) {
    handle_ = newHandle;
}

DWORD Process::pid() const {
    return pid_;
}

void Process::setPid(DWORD newPid) {
    pid_ = newPid;
}

QString Process::name() const {
    return name_;
}

void Process::setName(const QString &newName) {
    name_ = newName;
}

QString Process::state() const {
    return state_;
}

void Process::setState(const QString &newState) {
    state_ = newState;
}

QString Process::priority() const {
    return priority_;
}

void Process::setPriority(const QString newPriority) {
    priority_ = newPriority;
}

double Process::cputime() const {
    return cputime_;
}

void Process::setCputime(double newCputime) {
    cputime_ = newCputime;
}

size_t Process::workingSet() const {
    return workingSet_;
}

void Process::setWorkingSet(size_t newWorkingSet) {
    workingSet_ = newWorkingSet;
}

size_t Process::peakWorkingSet() const {
    return peakWorkingSet_;
}

void Process::setPeakWorkingSet(size_t newPeakWorkingSet) {
    peakWorkingSet_ = newPeakWorkingSet;
}

bool Process::isSuspended() {
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE)
        return false;

    THREADENTRY32 te;
    ZeroMemory(&te, sizeof(THREADENTRY32));
    te.dwSize = sizeof(THREADENTRY32);

    if (!Thread32First(hSnapshot, &te)) {
        CloseHandle(hSnapshot);
        return false;
    }

    do {
        if (te.th32OwnerProcessID == pid_) {
            HANDLE hThread = OpenThread(THREAD_SUSPEND_RESUME, FALSE, te.th32ThreadID);
            if (hThread) {
                DWORD suspendCount = SuspendThread(hThread);

                if (suspendCount == static_cast<DWORD>(-1)) {
                    CloseHandle(hThread);
                    CloseHandle(hSnapshot);
                    return false;
                }

                ResumeThread(hThread);

                if (suspendCount == 0)
                    return false;

                CloseHandle(hThread);
            }
        }
    } while (Thread32Next(hSnapshot, &te));

    CloseHandle(hSnapshot);
    return true;
}

DWORD_PTR Process::affinity() const {
    return affinity_;
}

void Process::setAffinity(DWORD_PTR newAffinity) {
    affinity_ = newAffinity;
}
