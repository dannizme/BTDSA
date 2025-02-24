#include <iostream>

struct Fraction
{
    int numer;
    int denom;
};

void enterFraction(Fraction &frac)
{
    std::cout << "Enter numerator: ";
    std::cin >> frac.numer;
    std::cout << "Enter denominator; ";
    std::cin >> frac.denom;
}

void printFraction(Fraction frac)
{
    std::cout << frac.numer << "/" << frac.denom << "\n";
}

int GCD(int a, int b)
{
    if (a % b == 0)
        return b;
    return GCD(b, a % b);
}

void reduceFraction(Fraction &frac)
{
    int gcd = GCD(frac.numer, frac.denom);
    frac.numer /= gcd;
    frac.denom /= gcd;
}

int compareFraction(Fraction frac1, Fraction frac2)
{
    double value = (double)frac1.numer / frac1.denom - (double)frac2.numer / frac2.denom;
    if (value > 0)
    {
        return 1;
    }
    else if (value == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

Fraction addFraction(Fraction frac1, Fraction frac2)
{
    Fraction result;
    result.numer = frac1.numer * frac2.denom + frac2.numer * frac1.denom;
    result.denom = frac1.denom * frac2.denom;
    return result;
}

Fraction subtractFraction(Fraction frac1, Fraction frac2)
{
    Fraction result;
    result.numer = frac1.numer * frac2.denom - frac2.numer * frac1.denom;
    result.denom = frac1.denom * frac2.denom;
    return result;
}

Fraction multiplyFraction(Fraction frac1, Fraction frac2)
{
    Fraction result;
    result.numer = frac1.numer * frac2.numer;
    result.denom = frac1.denom * frac2.denom;
    return result;
}

Fraction divideFraction(Fraction frac1, Fraction frac2)
{
    Fraction result;
    result.numer = frac1.numer * frac2.denom;
    result.denom = frac1.denom * frac2.numer;
    return result;
}

int main()
{
    Fraction frac1, frac2;
    enterFraction(frac1);
    enterFraction(frac2);
    printFraction(frac1);
    printFraction(frac2);
    reduceFraction(frac1);
    reduceFraction(frac2);
    printFraction(frac1);
    printFraction(frac2);
    std::cout << compareFraction(frac1, frac2) << "\n";
    printFraction(addFraction(frac1, frac2));
    printFraction(subtractFraction(frac1, frac2));
    printFraction(multiplyFraction(frac1, frac2));
    printFraction(divideFraction(frac1, frac2));
    return 0;
}