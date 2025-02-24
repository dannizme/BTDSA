#include <iostream>

bool checkVowel(char c)
{
    c = tolower(c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
        return true;
    }
    return false;
}

void sepeVowels(char *a, int n, char **b, int *count)
{
    *count = 0;
    for (int i = 0; i < n; i++)
    {
        if (checkVowel(a[i]))
        {
            (*count)++;
        }
    }

    *b = new char[*count];

    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (checkVowel(a[i]))
        {
            (*b)[index++] = a[i];
        }
    }
}

int main()
{
    int n;
    std::cin >> n;

    char *a = new char[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    char *b = nullptr;
    int count = 0;
    sepeVowels(a, n, &b, &count);

    for (int i = 0; i < count; i++)
    {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;

    delete[] a;
    delete[] b;

    return 0;
}