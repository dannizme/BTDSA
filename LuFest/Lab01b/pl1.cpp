#include <iostream>
#include <cmath>

void solve(int a, int b, int c, double *x1, double *x2, int *numSolutions)
{
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                *numSolutions = -1; // Vô số nghiệm
            }
            else
            {
                *numSolutions = 0; // Vô nghiệm
            }
        }
        else
        {
            *numSolutions = 1; // Nghiệm duy nhất
            *x1 = -1.0 * c / b;
        }
    }
    else
    {
        double delta = b * b - 4 * a * c;
        if (delta < 0)
        {
            *numSolutions = 0; // Vô nghiệm
        }
        else if (delta == 0)
        {
            *numSolutions = 1; // Nghiệm kép
            *x1 = -1.0 * b / (2 * a);
        }
        else
        {
            *numSolutions = 2; // Hai nghiệm phân biệt
            *x1 = (-b + sqrt(delta)) / (2 * a);
            *x2 = (-b - sqrt(delta)) / (2 * a);

            // Đảm bảo nghiệm nhỏ hơn là x1, lớn hơn là x2
            if (*x1 > *x2)
            {
                std::swap(*x1, *x2);
            }
        }
    }
}

int main()
{
    int a, b, c;
    double x1, x2;
    int numSolutions;

    std::cout << "Enter the values of a, b, c: ";
    std::cin >> a >> b >> c;

    solve(a, b, c, &x1, &x2, &numSolutions);

    // In kết quả
    if (numSolutions == -1)
    {
        std::cout << "Vo so nghiem\n";
    }
    else if (numSolutions == 0)
    {
        std::cout << "Vo nghiem\n";
    }
    else if (numSolutions == 1)
    {
        std::cout << "Nghiem duy nhat: " << x1 << "\n";
    }
    else if (numSolutions == 2)
    {
        std::cout << "2 nghiem phan biet: " << x1 << " and " << x2 << "\n";
    }

    return 0;
}
