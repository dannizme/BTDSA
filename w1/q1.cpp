#include <iostream>
#include <cmath>
#include <iomanip>

void swap(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}

void solve(int a, int b, int c)
{
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                std::cout << "Vo so nghiem\n";
            }
            else
            {
                std::cout << "Vo nghiem\n";
            }
        }
        else
        {
            std::cout << "Nghiem duy nhat: " << std::fixed << std::setprecision(2) << -1.0 * c / b << "\n";
        }
    }
    else
    {
        float d = b * b - 4 * a * c;
        if (d < 0)
        {
            std::cout << "Vo nghiem\n";
        }
        else if (d == 0)
        {
            std::cout << "Nghiem kep: " << std::fixed << std::setprecision(2) << -1.0 * b / (2 * a) << "\n";
        }
        else
        {
            double x1 = (-b + sqrt(d)) / (2 * a);
            double x2 = (-b - sqrt(d)) / (2 * a);

            if (x1 > x2)
            {
                swap(x1, x2);
            }
            std::cout << "2 nghiem phan biet : "
                      << std::fixed << std::setprecision(2) << x1 << " and " << x2 << "\n";
        }
    }
}

int main()
{
    int a, b, c;
    std::cout << "Enter the values of a, b, c: ";
    std::cin >> a >> b >> c;
    solve(a, b, c);

    return 0;
}
