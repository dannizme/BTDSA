#include <iostream>

void stringConcatenation(int *a, int sizeA, int *b, int sizeB, int **c, int *sizeC)
{
    *sizeC = sizeA + sizeB;

    *c = new int[*sizeC];
    int index1 = 0;
    int index2 = 0;
    int index3 = 0;

    while (index1 < sizeA && index2 < sizeB)
    {
        if (a[index1] < b[index2])
        {
            (*c)[index3++] = a[index1++];
        }
        else
        {
            (*c)[index3++] = b[index2++];
        }
    }

    while (index1 < sizeA)
    {
        (*c)[index3++] = a[index1++];
    }

    while (index2 < sizeB)
    {
        (*c)[index3++] = b[index2++];
    }
}

int main()
{
    int m;
    std::cin >> m;
    int *a = new int[m];
    for (int i = 0; i < m; i++)
    {
        std::cin >> a[i];
    }

    int n;
    std::cin >> n;
    int *b = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> b[i];
    }

    int *c = nullptr;
    int size = 0;
    stringConcatenation(a, m, b, n, &c, &size);

    for (int i = 0; i < size; i++)
    {
        std::cout << c[i] << " ";
    }

    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}