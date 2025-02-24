#include <iostream>
#include <string>

void insertCharAtPosition(std::string &str, char c, int pos)
{
    if (pos < 0 || pos > str.length())
    {
        std::cout << "Invalid position!";
        return;
    }

    str.resize(str.length() + 1);
    for (int i = str.length() - 1; i > pos; i--)
    {
        str[i] = str[i - 1];
    }
    str[pos] = c;
}

int main()
{
    std::string str;
    getline(std::cin, str);
    char c;
    int pos;
    std::cin >> c >> pos;
    insertCharAtPosition(str, c, pos);
    std::cout << str;

    return 0;
}