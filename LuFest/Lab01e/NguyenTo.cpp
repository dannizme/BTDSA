#include <iostream>
#include <fstream>
#include <cmath>

#define FI "NT.inp"
#define FO "NT.out"

bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    }

    int k = sqrt(n);

    for (int i = 2; i <= k; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void interchangeSort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                swap(a[i], a[j]);
            }
        }
    }
}

void inputData(int *&a, int &n)
{
    std::ifstream fi(FI);

    if (!fi)
    {
        std::cerr << " Can not open the file !\n";
        exit(0);
    }

    fi >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        fi >> a[i];
    }
    fi.close();
}

void outputData(int *a, int n)
{
    std::ofstream fo(FO);

    if (!fo)
    {
        std::cerr << " Can not create the file !\n";
        exit(0);
    }
    int count = 0;
    int *temp = new int[n];

    for (int i = 0; i < n; i++)
    {
        if (isPrime(a[i]))
        {
            temp[count++] = a[i];
        }
    }

    interchangeSort(temp, count);

    fo << count << "\n";
    for (int i = 0; i < count; i++)
    {
        fo << temp[i] << " ";
    }

    delete[] temp;
}

int main()
{
    int n;
    int *a = nullptr;
    inputData(a, n);
    outputData(a, n);

    delete[] a;
    return 0;
}