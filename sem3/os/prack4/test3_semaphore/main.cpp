#include <windows.h>
#include <iostream>

int sum = 2086;
HANDLE sem1;				// Semafor - kernel object
//активне оч≥куванн€
// ƒ¬≤… ќ¬»… —≈ћј‘ќ– != mutex
// Semaphore problems - doesn't have an owner, so release can be done by other thread
// Advantages - can be used as counter for resources (if not binary)

DWORD WINAPI MySalary(LPVOID CP) {
	for (int i = 0; i < 100000; i++) {
		WaitForSingleObject(sem1, INFINITE); // if 0 -> blocked
											 // if >0 -> CS
		sum++;				// Critical section
		ReleaseSemaphore(sem1, 1, NULL);
				// sem++
	}

	return 0;
}

DWORD WINAPI MyShopping(LPVOID CP) {
	for (int i = 0; i < 100000; i++) {
		WaitForSingleObject(sem1, INFINITE); // if 0 -> blocked
											 // if >0 -> CS
		sum--;				// Critical section
		ReleaseSemaphore(sem1, 1, NULL);
	}

	return 0;
}

int main() {
	HANDLE th1, th2;

	th1 = CreateThread(NULL, 0, MySalary, NULL, 0, 0);
	th2 = CreateThread(NULL, 0, MyShopping, NULL, 0, 0);

	sem1 = CreateSemaphore(NULL, 1/*start*/, 1/*max*/, NULL);
							// Max - max number of cells in buffer
							// Initial - how many are already full
							// Ќаприклад, у б≥бл≥отец≥ 5 ст≥льц≥в/файл≥в/об'Їкт≥в mutex
							// к≥льк≥сть в≥льних 3
							// -> start = 3, max = 5
							// WFSO(sem1, INFINITE)
							// if start == 0 -> blocked
							// else start--
							// ReleaseSemaphore(sem1, 6 /*start + 6 - how many to add*, but usually 1*/, lastStart - initial start value, usually NULL); 
								
	WaitForSingleObject(th1, INFINITE);
	WaitForSingleObject(th2, INFINITE);

	CloseHandle(th1);
	CloseHandle(th2);

	CloseHandle(sem1);

	std::cout << sum;
}

// sem1 = CreateSemaphore(NULL, 5, 5, NULL)