#include <Windows.h>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#define NUM_THREADS 100
#define TABLES 4

HANDLE semaphore;

DWORD WINAPI Read(LPVOID param) {
    int threadID = *(int*)param;
    delete (int*)param;

    WaitForSingleObject(semaphore, 99999999999);

    // Output when starting to read
    std::string msg = "Reader #" + std::to_string(threadID) + " started reading.\n";
    std::cout << msg;

    Sleep(1000);  // Thread simulates reading

    msg = "Reader #" + std::to_string(threadID) + " finished reading.\n";
    std::cout << msg;

    ReleaseSemaphore(semaphore, 1, NULL);

    return 0;
}

int main() {
    semaphore = CreateSemaphore(NULL, TABLES, TABLES, NULL);
    if (semaphore == NULL) {
        std::cerr << "CreateSemaphore error: " << GetLastError() << "\n";
        return 1;
    }

    // Create multiple threads
    HANDLE threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        int* threadID = new int(i);

        threads[i] = CreateThread(NULL, 0, Read, threadID, 0, NULL);

        if (threads[i] == NULL) {
            std::cerr << "CreateThread error: " << GetLastError() << "\n";
            delete threadID;
            return 1;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(std::rand() % 1000));
    }

    getchar();
    std::cout << "STOPPED\n";
    WaitForMultipleObjects(NUM_THREADS, threads, TRUE, INFINITE);

    for (int i = 0; i < NUM_THREADS; ++i) {
        CloseHandle(threads[i]);
    }

    CloseHandle(semaphore);

    return 0;
}