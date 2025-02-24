#include <iostream>
#include <string>

int countWords(std::string str)
{
    int count = 0;
    bool inWord = false;

    for (char c : str)
    {
        if (c != ' ')
        {
            if (!inWord)
            {
                count++;
                inWord = true;
            }
        }
        else
        {
            inWord = false;
        }
    }

    return count;
}

int main()
{
    std::string str;
    std::getline(std::cin, str);

    int wordCount = countWords(str);
    std::cout << "Number of words: " << wordCount << std::endl;

    return 0;
}