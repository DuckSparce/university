// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <iostream> 
#include "DynamicLib.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C" PORT_DLL void CALLBACK ShowMessage(HWND hwnd, HINSTANCE hinst, LPSTR lpszCmdLine, int nCmdShow) {
    MessageBox(hwnd, L"Hello from DLL!", L"Message", MB_OK);
}

extern "C" void PORT_DLL fnDynamicLib() {
    std::cout << "Inside dynamic library tabulation function: a = 1, b = 100, n = 100.\n";

    double a = 1;
    double b = 100;
    int n = 100;
    double h = (b - a) / n;

    for (double x = a; x < b; x += h) {
        double y = (pow(cos(x), 2) + pow(cos(x), 3)) / fabs(1 / x);
        std::cout << "For x = " << x << " y = " << y << '\n';
    }

    std::cout << "End of dynamic library function.\n";
}
