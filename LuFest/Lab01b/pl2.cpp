#include <iostream>

bool checkEvenAndOdd(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] % 2 == a[i + 1] % 2)
            return false;
    }
    return true;
}

bool checkEven(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] % 2 != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    std::cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    if (checkEvenAndOdd(a, n))
    {
        std::cout << "Day co tinh chat chan le.\n";
    }
    else
    {
        std::cout << "Day khong co tinh chat chan le.\n";
    }

    if (checkEven(a, n))
    {
        std::cout << "Day co tinh chat chan.\n";
    }
    else
    {
        std::cout << "Day khong co tinh chat chan.\n";
    }

    delete[] a;

    return 0;
}