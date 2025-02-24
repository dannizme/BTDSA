#include <iostream>
#include <fstream>

#define FI "input.inp"

void inputData(int &n)
{
    std::ifstream fi(FI);

    if (!fi)
    {
        std::cerr << "Can not open the file !\n";
        exit(0);
    }

    fi >> n;
    fi.close();
}

int main()
{
    int n;
    inputData(n);
    std::cout << "n= " << n << '\n';

    return 0;
}