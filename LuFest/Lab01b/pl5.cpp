#include <iostream>

void sepeString(int *a, int sizeA, int **b, int *sizeB, int **c, int *sizeC)
{
    *sizeB = 0;
    *sizeC = 0;

    *b = new int[sizeA];
    *c = new int[sizeA];

    for (int i = 0; i < sizeA; i++)
    {
        if (a[i] % 2 == 0)
        {
            (*b)[(*sizeB)++] = a[i];
        }
        else
        {
            (*c)[(*sizeC)++] = a[i];
        }
    }
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

    int *b = nullptr;
    int sizeB = 0;

    int *c = nullptr;
    int sizeC = 0;

    sepeString(a, n, &b, &sizeB, &c, &sizeC);

    for (int i = 0; i < sizeB; i++)
    {
        std::cout << b[i] << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < sizeC; i++)
    {
        std::cout << c[i] << " ";
    }

    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}