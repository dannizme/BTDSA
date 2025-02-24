#include <iostream>
#include <string>

struct Flower
{
    std::string name;
    int quantity;
    std::string unit;
    int price;

    static Flower list[20];
    static int count;
};

Flower Flower::list[20];
int Flower::count = 0;

void inputFlowerInfo()
{
    if (Flower::count >= 20)
    {
        std::cout << "Flower list is full.\n";
        return;
    }

    Flower flower;
    std::cout << "Enter name: ";
    std::cin.ignore();
    std::getline(std::cin, flower.name);
    std::cout << "Enter quantity: ";
    std::cin >> flower.quantity;
    std::cout << "Enter unit: ";
    std::cin >> flower.unit;
    std::cout << "Enter price: ";
    std::cin >> flower.price;

    Flower::list[Flower::count++] = flower;
}

void printFlowerList()
{
    if (Flower::count == 0)
    {
        std::cout << "Flower list is empty.\n";
        return;
    }

    for (int i = 0; i < Flower::count; i++)
    {
        std::cout << "Flower " << i + 1 << "\n";
        std::cout << "Name: " << Flower::list[i].name << "\n";
        std::cout << "Quantity: " << Flower::list[i].quantity << "\n";
        std::cout << "Unit: " << Flower::list[i].unit << "\n";
        std::cout << "Price: " << Flower::list[i].price << "\n";
    }
}

std::string toLower(const std::string &str)
{
    std::string result;
    for (char c : str)
    {
        if (c >= 'A' && c <= 'Z')
        {
            result += c + 32; // Chuyển chữ hoa thành chữ thường
        }
        else
        {
            result += c;
        }
    }
    return result;
}

int searchFlowerByName(std::string name)
{
    std::string lowerName = toLower(name);

    for (int i = 0; i < Flower::count; i++)
    {
        if (toLower(Flower::list[i].name) == lowerName)
        {
            return i;
        }
    }

    return -1;
}

int sellingFlowerAdmin(std::string name, int quantity)
{
    int index = searchFlowerByName(name);
    if (index == -1)
    {
        std::cout << "Flower not found\n";
        return -1;
    }

    if (Flower::list[index].quantity < quantity)
    {
        std::cout << "Not enough flower\n";
        return -1;
    }

    int total = quantity * Flower::list[index].price;
    Flower::list[index].quantity -= quantity;

    return total;
}

int main()
{
    int choice;

    do
    {
        std::cout << "\n=== Flower Management ===\n";
        std::cout << "1. Add Flower\n";
        std::cout << "2. Print Flower List\n";
        std::cout << "3. Sell Flower\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            inputFlowerInfo();
            break;
        case 2:
            printFlowerList();
            break;
        case 3:
        {
            std::string name;
            int quantity;
            std::cin.ignore();
            std::cout << "Enter flower name: ";
            std::getline(std::cin, name);
            std::cout << "Enter quantity to sell: ";
            std::cin >> quantity;

            int total = sellingFlowerAdmin(name, quantity);
            if (total != -1)
            {
                std::cout << "Total price: " << total << "\n";
            }
            break;
        }
        case 0:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
