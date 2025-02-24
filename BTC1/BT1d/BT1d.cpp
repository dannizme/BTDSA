#include <iostream>
#include <cmath>

bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    }

    int k = sqrt(n);

    for (int i = 2; i <= k; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

void findResult(int *arr, int n)
{
    bool **result = new bool *[3];
    for (int i = 0; i < 3; i++)
    {
        result[i] = new bool[n];
        std::fill(result[i], result[i] + n, false);
    }

    for (int i = 0; i < n; i++)
    {
        if (isPrime(arr[i]))
        {
            result[0][i] = true;
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            result[1][i] = true;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (result[0][i] && result[1][i])
        {
            result[2][i] = true;
        }
    }

    int start = 0, bestStart = 0;
    int count = 0;
    int maxLength = 1;

    for (int i = 0; i < n; i++)
    {
        if (result[2][i])
        {
            if (count == 0)
            {
                start = i;
            }
            count++;
        }
        else
        {
            if (count > maxLength)
            {
                maxLength = count;
                bestStart = start;
            }
            count = 0;
        }
    }
    if (count > maxLength)
    {
        maxLength = count;
        bestStart = start;
    }

    for (int i = bestStart; i < bestStart + maxLength; i++)
    {
        std::cout << arr[i] << " ";
    }

    for (int i = 0; i < 3; i++)
    {
        delete[] result[i];
    }
    delete[] result;
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