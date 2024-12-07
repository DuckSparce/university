#include <windows.h>
#include <iostream>

volatile /*volatile = atomic*/ long /*only long works correctly*/ sum = 2086;
//активне очікування

DWORD WINAPI MySalary(LPVOID CP) {
	for (int i = 0; i < 100000; i++) {
		// sum++;				// Critical section
		// ^^^ same
		InterlockedIncrement(&sum);

		// There is also
		// InterlockedCompareExchange(sum, sum2, sum1)
		// InterlockedCompareExchangeAdd(sum, sum2, sum1)
	}

	return 0;
}

DWORD WINAPI MyShopping(LPVOID CP) {
	for (int i = 0; i < 100000; i++) {
		//sum--;				// Critical section
		// ^^^ same
		InterlockedDecrement(&sum);
	}

	return 0;
}

int main() {
	HANDLE th1, th2;

	th1 = CreateThread(NULL, 0, MySalary, NULL, 0, 0);
	th2 = CreateThread(NULL, 0, MyShopping, NULL, 0, 0);

	WaitForSingleObject(th1, INFINITE);
	WaitForSingleObject(th2, INFINITE);

	CloseHandle(th1);
	CloseHandle(th2);

	std::cout << sum;
}