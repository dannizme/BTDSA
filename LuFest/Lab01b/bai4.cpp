#include <iostream>

bool checkAlternating(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] * a[i + 1] >= 0)
            return false;
    }
    return true;
}

bool checkMonoIncreasing(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            return false;
        }
    }
    return true;
}

bool checkSymmetry(int *a, int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        if (a[i] != a[n - i - 1])
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

    if (checkAlternating(a, n))
    {
        std::cout << "Day co tinh chat dan dau.\n";
    }
    else
    {
        std::cout << "Day khong co tinh chat dan dau.\n";
    }

    if (checkMonoIncreasing(a, n))
    {
        std::cout << "Day co tinh don dieu.\n";
    }
    else
    {
        std::cout << "Day khong co tinh don dieu.\n";
    }

    if (checkSymmetry(a, n))
    {
        std::cout << "Day co tinh chat doi xung.\n";
    }
    else
    {
        std::cout << "Day khong co tinh chat doi xung.\n";
    }

    delete[] a;

    return 0;
}