#include <iostream>

void HoanVi1(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void HoanVi2(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void HoanVi3(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int x = 5, y = 10;
    std::cout << "x = " << x << " y = " << y << "\n";
    HoanVi1(x, y);
    std::cout << "x = " << x << " y = " << y << "\n";

    int a = 5, b = 10;
    std::cout << "a = " << a << " b = " << b << "\n";
    HoanVi2(a, b);
    std::cout << "a = " << a << " b = " << b << "\n";

    int m = 5, n = 10;
    std::cout << "m = " << m << " n = " << n << "\n";
    HoanVi3(&m, &n);
    std::cout << "m = " << m << " n = " << n << "\n";

    int p = 5;
    int &q = p;

    std::cout << "Addr = " << &p << ", Val = " << p << "\n";
    std::cout << "Addr = " << &q << ", Val = " << q << "\n";

    return 0;
}