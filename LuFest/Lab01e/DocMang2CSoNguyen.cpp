#include <iostream>
#include <fstream>

#define FI "MangSo.inp"

void inputData(int **&a, int &rows, int &cols)
{
    std::ifstream fi(FI);

    if (!fi)
    {
        std::cerr << "Can not open the file!\n";
        exit(0);
    }

    fi >> rows >> cols;
    a = new int *[rows];

    for (int i = 0; i < rows; i++)
    {
        a[i] = new int[cols];
        for (int j = 0; j < cols; j++)
        {
            fi >> a[i][j];
        }
    }

    fi.close();
}

void outputData(int **a, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int **a;
    int rows, cols;

    inputData(a, rows, cols);

    outputData(a, rows, cols);
    // Giải phóng bộ nhớ
    for (int i = 0; i < rows; i++)
    {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
