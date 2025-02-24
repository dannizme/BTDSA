#include <iostream>
#include <fstream>

#define FI "DaySoNguyen.inp"

void inputData(int *&a, int &n)
{
    std::ifstream fi(FI);

    if (!fi)
    {
        std::cerr << "Can not open the file !\n";
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

int main()
{
    int n;
    int *a = nullptr;
    inputData(a, n);

    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }

    delete[] a;

    return 0;
}