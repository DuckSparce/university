#ifndef DYNAMIC_LIB_H_
#define DYNAMIC_LIB_H_

#define PORT_DLL __declspec(dllexport)

extern "C" void PORT_DLL fnDynamicLib();

extern "C" PORT_DLL void CALLBACK ShowMessage(HWND hwnd, HINSTANCE hinst, LPSTR lpszCmdLine, int nCmdShow);

#endif // DYNAMIC_LIB_H_
