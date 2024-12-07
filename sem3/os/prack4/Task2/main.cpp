#include <Windows.h>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <string>
#include <cstdlib>

#define NUM_THREADS 50
#define NUM 3
#define DOOR_CAPACITY 2

HANDLE doors[NUM];
int count = 0;
HANDLE countMutex;

DWORD WINAPI GoShopping(LPVOID param) {
    int threadID = *(int*)param;
    delete (int*)param;

    DWORD i = WaitForMultipleObjects(NUM, doors, false, INFINITE) - WAIT_OBJECT_0;

    if (i >= 0 && i < NUM) {
        WaitForSingleObject(countMutex, INFINITE);
        count++;
        
        std::string msg = "New customer #" + std::to_string(threadID) + " at door #" + std::to_string(i)
                          + "\t\tCurrent customer count = " + std::to_string(count) + '\n';
        std::cout << msg;

        ReleaseMutex(countMutex);

        Sleep(3000);

        WaitForSingleObject(countMutex, INFINITE);
        count--;

        msg = "Exited customer #" + std::to_string(threadID) + " at door #" + std::to_string(i)
                          + "\t\tCurrent customer count = " + std::to_string(count) + '\n';
        std::cout << msg;

        ReleaseMutex(countMutex);

        ReleaseSemaphore(doors[i], 1, NULL);
    }


    return 0;
}

int main() {
    countMutex = CreateMutex(NULL, FALSE, TEXT("CountMutex"));

    for (int i = 0; i < NUM; i++) {
        doors[i] = CreateSemaphore(NULL, NUM, NUM, NULL);
        
        if (doors[i]  == NULL) {
            std::cerr << "CreateSemaphore error at door #: " << i << "\n";
            return 1;
        }
    }

    HANDLE threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        int* threadID = new int(i);

        threads[i] = CreateThread(NULL, 0, GoShopping, threadID, 0, NULL);

        if (threads[i] == NULL) {
            std::cerr << "CreateThread error: " << GetLastError() << "\n";
            delete threadID;
            return 1;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    getchar();
    WaitForMultipleObjects(NUM_THREADS, threads, TRUE, INFINITE);

    for (int i = 0; i < NUM_THREADS; ++i) {
        CloseHandle(threads[i]);
    }

    for (int i = 0; i < NUM; i++) {
        CloseHandle(doors[i]);
    }

    return 0;
}