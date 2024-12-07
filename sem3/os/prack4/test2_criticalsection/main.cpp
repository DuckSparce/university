#include <windows.h>
#include <iostream>

int sum = 2086;
CRITICAL_SECTION CS1;		// not kernel object so can't be used for processes

//активне очікування

DWORD WINAPI MySalary(LPVOID CP) {
	for (int i = 0; i < 100000; i++) {
		EnterCriticalSection(&CS1);
		sum++;				// Critical section
		LeaveCriticalSection(&CS1);
	}

	return 0;
}

DWORD WINAPI MyShopping(LPVOID CP) {
	for (int i = 0; i < 100000; i++) {
		EnterCriticalSection(&CS1);				// If not free -> active waiting < 1000 blocked
		sum--;				// Critical section
		LeaveCriticalSection(&CS1);
	}

	return 0;
}

int main() {
	HANDLE th1, th2;
	InitializeCriticalSection(&CS1);

	th1 = CreateThread(NULL, 0, MySalary, NULL, 0, 0);
	th2 = CreateThread(NULL, 0, MyShopping, NULL, 0, 0);

	WaitForSingleObject(th1, INFINITE);
	WaitForSingleObject(th2, INFINITE);

	CloseHandle(th1);
	CloseHandle(th2);

	DeleteCriticalSection(&CS1);

	std::cout << sum;
}