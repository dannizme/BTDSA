#include <iostream>
#include <string>

void removeAtPosition(std::string &str, int pos)
{
    if (pos < 0 || pos >= str.length())
    {
        std::cout << "Invalid position!";
        return;
    }

    for (int i = pos; i < str.length() - 1; i++)
    {
        str[i] = str[i + 1];
    }

    str.resize(str.length() - 1);
}
int main()
{
    std::string str;
    getline(std::cin, str);
    int pos;
    std::cin >> pos;
    removeAtPosition(str, pos);
    std::cout << str;

    return 0;
}