#include <iostream>
#include <algorithm>

void findLongestArr(int *arr, int n)
{
    bool *temp = new bool[n]; // time complexity: O(n) - space complexity: O(n)
    std::fill(temp, temp + n, false);

    for (int i = 0; i < n; i++) // time complexity: O(n) - space complexity: O(n)
    {
        if (arr[i] % 2 == 0)
        {
            temp[i] = true;
        }
    }

    int max = 0;
    int count = 0;
    int flag = 0;
    for (int i = 0; i < n; i++) // time complexity: O(n) - space complexity: O(1)
    {
        if (temp[i])
        {
            count++;
            continue;
        }

        if (!temp[i])
        {
            if (count > max)
            {
                max = count;
                flag = i - count;
            }
            count = 0;
        }
    }

    if (count > max) // time complexity: O(1) - space complexity: O(1)
    {
        max = count;
        flag = n - count;
    }

    for (int i = flag; i < flag + max; i++) // time complexity: O(n) - space complexity: O(1)
    {
        std::cout << arr[i] << " ";
    }

    delete[] temp; // time complexity: O(1) - space complexity: O(1)
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

    findLongestArr(arr, n);

    delete[] arr;
    return 0;
}