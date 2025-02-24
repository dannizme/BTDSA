#include <iostream>
#define MAX 100

void NhapMang(int *&a, int &n)
{
    std::cout << "Moi ban nhap so luong phan tu: ";
    std::cin >> n;
    a = new int[n];
    for (int i = 0; i <= n - 1; i++)
    {
        std::cout << "Phan tu " << i << ": ";
        std::cin >> a[i];
    }
}

void NhapMang(int **a, int *n)
{
    std::cout << "Moi ban nhap so luong phan tu: ";
    std::cin >> *n;
    *a = new int[*n];
    for (int i = 0; i <= *n - 1; i++)
    {
        std::cout << "Phan tu " << i << ": ";
        std::cin >> (*a)[i];
    }
}

void XuatMang(int *a, int n)
{
    std::cout << "Day so co " << n << " phan tu: ";
    for (int i = 0; i <= n - 1; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

void DoiChan(int *a, int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        if (a[i] % 2 == 0)
        {
            a[i] = 0;
        }
    }
}

int main()
{
    int *b = nullptr;
    int k = 0;

    NhapMang(&b, &k);

    XuatMang(b, k);

    DoiChan(b, k);
    std::cout << "* Doi gia tri chan thanh cac so 0: \n";
    XuatMang(b, k);

    if (b != nullptr)
        delete[] b;

    return 0;
}
