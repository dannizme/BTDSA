#include <iostream>
#define MAX 100

void NhapMang(int **a, int *n)
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

void XuatMang(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

int DemChan(int *a, int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
            dem++;
    }
    return dem;
}

void TachChan(int *a, int n, int **b, int *m)
{
    *m = DemChan(a, n);
    *b = new int[*m];
    int cs = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            (*b)[cs++] = a[i];
        }
    }
}

int main()
{
    int *b = nullptr;
    int k = 0;
    int *aChan = nullptr;
    int nChan = 0;

    NhapMang(&b, &k);
    TachChan(b, k, &aChan, &nChan);

    if (nChan > 0)
    {
        std::cout << "+ Day chua cac so chan\n";
        XuatMang(aChan, nChan);
    }
    else
    {
        std::cout << "Khong co day phu hop\n";
    }

    delete[] b;
    delete[] aChan;

    return 0;
}
