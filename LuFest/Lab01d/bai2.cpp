#include <iostream>
#include <string>

bool check(std::string str)
{
    int start = 0;
    int end = str.length() - 1;
    while (start < end)
    {
        if (str[start] != str[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main()
{
    std::string str;
    getline(std::cin, str);

    if (check(str))
    {
        std::cout << "La chuoi doi xung.";
    }
    else
    {
        std::cout << "Khong la chuoi doi xung.";
    }

    return 0;
}