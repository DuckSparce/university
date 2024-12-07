#include <iostream>
#include <dlfcn.h>

void (*func)();
    
int main() {
    void* dynamic_lib = dlopen("./libdynamic.so", RTLD_LAZY);
    *(void**)(&func) = dlsym(dynamic_lib, "libdynamic_func");
    func();
    dlclose(dynamic_lib);
}

