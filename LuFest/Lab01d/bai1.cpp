#include <iostream>
#include <string>

bool check(std::string str)
{
    for (char c : str)
    {
        if (c >= '0' && c <= '9')
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::string str;
    getline(std::cin, str);

    if (check(str))
    {
        std::cout << "Khong co ki tu so.";
    }
    else
    {
        std::cout << "Co ki tu so.";
    }

    return 0;
}