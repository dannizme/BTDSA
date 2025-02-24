#include <iostream>

int main()
{
    int a[5] = {2, 4, 5, 8};
    int na = 3;

    int *p = nullptr;
    p = a + 1;
    std::cout << "Addr = " << &p << ", Val = " << p << ", ValRef = " << *p << "\n";

    p = p + 1;

    int x = p[-2];

    int *b = nullptr;
    int nb = 0;

    nb = 3;
    b = new int[nb];

    *(b + 0) = 10;
    *(b + 1) = 20;
    b[2] = 30;

    if (b != nullptr)
    {
        delete[] b;
    }

    return 0;
}