#include <iostream>

int findMaxValue(int *arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
void findResult(int *arr, int n)
{
    int max = findMaxValue(arr, n);
    int *temp = new int[max + 1]();

    for (int i = 0; i < n; i++)
    {
        temp[arr[i]]++;
    }

    for (int i = 0; i < max + 1; i++)
    {
        if (temp[i] > 0)
        {
            std::cout << i << " -> " << temp[i] << "\n";
        }
    }

    delete[] temp;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    std::cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    findResult(arr, n);
    delete[] arr;

    return 0;
}