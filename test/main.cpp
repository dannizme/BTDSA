#include <iostream>
#include <cmath>
#include <string>

#include <algorithm>

using namespace std;

void findLongestArr(int *arr, int n)
{
    int count = 1, maxLength = 1;
    int start = 0, bestStart = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            count++;
        }
        else
        {
            if (count > maxLength)
            {
                maxLength = count;
                bestStart = start;
            }
            count = 1;
            start = i;
        }
    }

    if (count > maxLength)
    {
        maxLength = count;
        bestStart = start;
    }

    for (int i = bestStart; i < bestStart + maxLength; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    findLongestArr(arr, n);

    delete[] arr;

    return 0;
}