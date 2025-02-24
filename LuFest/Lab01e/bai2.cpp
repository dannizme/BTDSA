#include <iostream>
#include <fstream>

#define FO "output.out"

void createArray(int *&a, int n)
{
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
}

void outputData(int *a, int n)
{
    std::ofstream fo(FO);

    if (!fo)
    {
        std::cerr << "Can not create the file!" << std::endl;
        exit(0);
    }

    for (int i = 0; i < n; i++)
    {
        fo << a[i] << " ";
    }

    fo.close();
}

int main()
{
    int n;
    std::cin >> n;

    int *a;
    createArray(a, n);
    outputData(a, n);

    delete[] a;
    return 0;
}
