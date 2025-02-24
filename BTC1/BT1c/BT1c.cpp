#include <iostream>

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void interChangeSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}
int findTheLargestKinSub(int *arr, int n, int k)
{
    if (k <= 0 || k > n)
    {
        std::cout << "Invalid k!";
        return -1;
    }

    int *temp = new int[n];

    for (int i = 0; i < n; i++)
    {
        temp[i] = arr[i];
    }

    interChangeSort(temp, n);

    return temp[k - 1];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, k;
    std::cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    std::cin >> k;
    std::cout << findTheLargestKinSub(arr, n, k);

    delete[] arr;
    return 0;
}