#include <iostream>
#include <cmath>

#define MAX 100

void input(int **a, int *n)
{
    std::cout << "Moi ban nhap so luong phan tu: ";
    std::cin >> *n;
    while (*n <= 0 || *n > MAX)
    {
        std::cout << "Nhap sai! Nhap lai: ";
        std::cin >> *n;
    }
    *a = new int[*n];
    for (int i = 0; i < *n; i++)
    {
        std::cout << "Phan tu " << i << ": ";
        std::cin >> (*a)[i];
    }
}

void output(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

bool checkPrime(int n)
{
    if (n < 2)
        return false;

    int k = sqrt(n);
    for (int i = 2; i <= k; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void sepePrime(int *a, int n, int **b, int *m)
{
    *m = 0;
    for (int i = 0; i < n; i++)
    {
        if (checkPrime(a[i]))
        {
            (*m)++;
        }
    }

    if (*m > 0)
    {
        *b = new int[*m];
        int cs = 0;
        for (int i = 0; i < n; i++)
        {
            if (checkPrime(a[i]))
            {
                (*b)[cs++] = a[i];
            }
        }
    }
}

int main()
{
    int *b = nullptr;
    int k = 0;
    int *aPrime = nullptr;
    int nPrime = 0;

    input(&b, &k);
    sepePrime(b, k, &aPrime, &nPrime);

    if (nPrime > 0)
    {
        std::cout << "Day chua cac so nguyen to\n";
        output(aPrime, nPrime);
    }
    else
    {
        std::cout << "Khong co day phu hop\n";
    }

    delete[] b;
    delete[] aPrime;

    return 0;
}
