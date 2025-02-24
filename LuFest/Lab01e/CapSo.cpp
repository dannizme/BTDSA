#include <iostream>
#include <fstream>
#include <cmath>

#define FI "CapSo.inp"
#define FO "Capso.out"

template <typename T, typename U>
struct MyPair
{
    T first;
    U second;

    // MyPair(T a, U b) : first(a), second(b) {}
};

void inputData(int *&a, int &n, int &k)
{
    std::ifstream fi(FI);

    if (!fi)
    {
        std::cerr << " Can not open the file !\n";
        exit(0);
    }

    fi >> n >> k;
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        fi >> a[i];
    }
    fi.close();
}

bool isPairExist(MyPair<int, int> *rs, int count, int first, int second)
{
    for (int i = 0; i < count; i++)
    {
        if ((rs[i].first == first && rs[i].second == second) ||
            (rs[i].first == second && rs[i].second == first))
        {
            return true;
        }
    }
    return false;
}

void checkCondition(int *&a, MyPair<int, int> *&rs, int &n, int &k, int &count)
{
    count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] + a[j] == k)
            {
                if (!isPairExist(rs, count, a[i], a[j]))
                {
                    rs[count].first = a[i];
                    rs[count].second = a[j];
                    count++;
                }
            }
        }
    }
}

void outputData(MyPair<int, int> *rs, int &n)
{
    std::ofstream fo(FO);

    if (!fo)
    {
        std::cerr << "Can not create the file!" << std::endl;
        exit(0);
    }

    for (int i = 0; i < n; i++)
    {
        fo << rs[i].first << " " << rs[i].second << "\n";
    }

    fo.close();
}

int main()
{
    int n, k, count = 0;
    int *a = nullptr;
    MyPair<int, int> *rs;

    inputData(a, n, k);

    rs = new MyPair<int, int>[n];

    checkCondition(a, rs, n, k, count);

    outputData(rs, count);

    delete[] a;
    delete[] rs;

    return 0;
}
