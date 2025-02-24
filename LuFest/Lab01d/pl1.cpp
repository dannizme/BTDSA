#include <iostream>
#include <string>

void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

void interchangeSort(std::string &str)
{
    for (int i = 0; i < str.length() - 1; i++)
    {
        for (int j = i + 1; j < str.length(); j++)
        {
            if (str[i] > str[j])
            {
                swap(str[i], str[j]);
            }
        }
    }
}

int main()
{
    std::string str;
    getline(std::cin, str);
    interchangeSort(str);
    std::cout << str;
    return 0;
}