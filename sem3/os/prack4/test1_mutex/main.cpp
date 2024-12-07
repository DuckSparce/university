#include <windows.h>
#include <iostream>

int sum = 2086;
HANDLE mutex;				// Either global variable or parameter in main function call
							// Every resource should have its own mutex

DWORD WINAPI MySalary(LPVOID CP) {
	for (int i = 0; i < 100000; i++) {
		WaitForSingleObject(mutex, INFINITE);
		// if false -> critical section -> true
		// if true -> wait (blocked status)
		sum++;				// Critical section

		// the problem is that there is intermediate status to get the thread into ready queue
		ReleaseMutex(mutex);
	}

	return 0;
}

DWORD WINAPI MyShopping(LPVOID CP) {
	for (int i = 0; i < 100000; i++) {
		WaitForSingleObject(mutex, INFINITE);
		sum--;				// Critical section
		ReleaseMutex(mutex);
	}

	return 0;
}

int main() {
	HANDLE th1, th2;
	mutex = CreateMutex(NULL, false, NULL);			// 3 par: NULL - for threads, name - for processes
													// Every process has his own handle table
													// For system to know what process it is working with, it needs its name
													// 2 par: TRUE - main is the owner
													// FALSE - doesn't have an owner yet
													// if TRUE, than resume mutex in main
													// 



	th1 = CreateThread(NULL, 0, MySalary, NULL, 0, 0);
	th2 = CreateThread(NULL, 0, MyShopping, NULL, 0, 0);

	WaitForSingleObject(th1, INFINITE);
	WaitForSingleObject(th2, INFINITE);

	CloseHandle(th1);
	CloseHandle(th2);
	CloseHandle(mutex);

	std::cout << sum;

//PR2:
//	OpenMutex(, , name);
//  Mut2 = ...
}