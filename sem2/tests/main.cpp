#include <iostream>
#include <vector>

template<typename T>
class Foo {
public:
    Foo() {
        a = 5;
    }

private:
    int a;
    std::vector<T> v;
};

int main() {
    Foo<char> f1;
}
