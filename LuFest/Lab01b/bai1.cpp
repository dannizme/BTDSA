#include <iostream>

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{

    int x, y;

    std::cout << "Moi ban nhap so a: ";
    std::cin >> x;
    std::cout << "Moi ban nhap so b: ";
    std::cin >> y;

    std::cout << "Truoc khi hoan vi, a = " << x << " va b = " << y << ".\n";
    Swap(&x, &y);
    std::cout << "Sau khi hoan vi, a = " << x << " va b = " << y << ".\n";

    return 0;
}