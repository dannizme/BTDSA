#include <iostream>
#include <string>

class Goods
{
private:
    std::string id;
    std::string name;
    int quantity;
    int price;

    static Goods *list;
    static int countGoods;
    static int totalQuantity;

public:
    Goods() : id(""), name(""), quantity(0), price(0) {}
    Goods(std::string id, std::string name, int quantity, int price) : id(id), name(name), quantity(quantity), price(price) { totalQuantity += quantity; }

    static void addGoods()
    {
        int n;
        std::cout << "Enter number of goods: ";
        std::cin >> n;

        for (int i = 0; i < n; i++)
        {
            std::string id, name;
            int quantity, price;
            std::cout << "Enter ID: ";
            std::cin >> id;
            for (int j = 0; j < countGoods; j++)
            {
                if (list[j].id == id)
                {
                    std::cout << "ID " << id << " already exists. Skipping.\n";
                    return;
                }
            }
            std::cin.ignore();
            std::cout << "Enter name: ";
            getline(std::cin, name);
            std::cout << "Enter quantity: ";
            std::cin >> quantity;
            std::cout << "Enter price: ";
            std::cin >> price;
            list[countGoods++] = Goods(id, name, quantity, price);
        }
    }

    static void searchGoods(std::string name)
    {
        for (int i = 0; i < countGoods; i++)
        {
            if (list[i].name == name)
            {
                std::cout << "ID: " << list[i].id << "\n";
                std::cout << "Name: " << list[i].name << "\n";
                std::cout << "Quantity: " << list[i].quantity << "\n";
                std::cout << "Price: " << list[i].price << "\n";
                return;
            }
        }
        std::cout << "Goods not found." << "\n";
    }

    static int getTotalQuantity()
    {
        return totalQuantity;
    }
};

Goods *Goods::list = new Goods[100];
int Goods::countGoods = 0;
int Goods::totalQuantity = 0;

int main()
{
    Goods::addGoods();
    std::string name;
    std::cin.ignore();
    std::cout << "Enter name to search: ";
    getline(std::cin, name);
    Goods::searchGoods(name);

    std::cout << "Total quantity: " << Goods::getTotalQuantity() << "\n";

    return 0;
}