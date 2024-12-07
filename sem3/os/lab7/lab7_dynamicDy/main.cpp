#include <iostream>
#include <Windows.h>

typedef void(__cdecl* MYFUNC)();

int main() {
	MYFUNC func;
	HMODULE mylib = LoadLibrary((LPCWSTR)(L"C:\\Users\\USER\\source\\repos\\university\\sem3\\os\\lab7\\DynamicLib\\x64\\Debug\\DynamicLib.dll"));

	if (mylib == NULL) {
		std::cout << "Can`t open Lib " << GetLastError();
		return -1;
	}

	func = (MYFUNC)GetProcAddress(mylib, "fnDynamicLib");

	if (func == NULL) {
		std::cout << "Can`t open func " << GetLastError();
		return -1;
	}

	func();
	FreeLibrary(mylib);
}
