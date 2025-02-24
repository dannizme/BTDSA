#include <iostream>
#include <cmath>

bool checkSquare(int *n)
{
    int temp = sqrt(*n);
    return temp * temp == *n;
}

int main()
{
    int x;
    int *ptr = &x;

    std::cout << "Moi ban nhap so nguyen n: ";
    std::cin >> x;

    if (checkSquare(ptr))
    {
        std::cout << x << " la so chinh phuong.\n";
    }
    else
    {
        std::cout << x << " khong phai la so chinh phuong.\n";
    }

    return 0;
}