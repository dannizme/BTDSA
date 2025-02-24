#include <iostream>

int main()
{
    int n;

    int *p = nullptr;

    n = 20;
    p = &n;

    std::cout << "Addr = " << &n << ", Val = " << n << "\n";
    std::cout << "Addr = " << &p << ", Val = " << p << ", ValRef = " << *p << "\n";

    int *pn = nullptr;
    pn = new int;

    if (pn != nullptr)
    {
        *pn = 10;

        std::cout << "sizeof(int): " << sizeof(int) << " bytes(s)" << "\n";
        std::cout << "Addr = " << &pn << ", Val = " << pn << ", valRef = " << *pn << "\n";

        delete[] pn;
        pn = nullptr;
    }

    return 0;
}