#include <iostream>
#include <string>

class Phone
{
private:
    std::string id;
    std::string brand;
    int price;

    static Phone *list;
    static int countPhone;

public:
    Phone() : id(""), brand(""), price(0) {}

    Phone(std::string id, std::string brand, int price) : id(id), brand(brand), price(price) {}

    static bool isExist(std::string id)
    {
        for (int i = 0; i < countPhone; i++)
        {
            if (list[i].id == id)
            {
                return true;
            }
        }
        return false;
    }

    static void addPhone(Phone phone)
    {
        if (countPhone < 100)
        {
            if (!isExist(phone.id))
            {
                list[countPhone++] = phone;
            }
            else
            {
                std::cout << "Phone with id " << phone.id << " already exist in the system." << "\n";
            }
        }
        else
        {
            std::cout << "The system is full." << "\n";
        }
    }

    static void showInfoPhone(std::string id)
    {
        for (int i = 0; i < countPhone; i++)
        {
            if (list[i].id == id)
            {
                std::cout << "Phone ID: " << list[i].id << "\n";
                std::cout << "Phone Brand: " << list[i].brand << "\n";
                std::cout << "Phone Price: " << list[i].price << "\n";
                return;
            }
        }
        std::cout << "Phone not found." << "\n";
    }

    static void setPrice(std::string id)
    {
        for (int i = 0; i < countPhone; i++)
        {
            if (list[i].id == id)
            {
                std::cout << "Enter new price:";
                std::cin >> list[i].price;
                return;
            }
        }
        std::cout << "Phone not found." << "\n";
    }

    static void removePhone(std::string id)
    {
        for (int i = 0; i < countPhone; i++)
        {
            if (list[i].id == id)
            {
                for (int j = i; j < countPhone - 1; j++)
                {
                    list[j] = list[j + 1];
                }
                countPhone--;
                return;
            }
        }
        std::cout << "Phone not found." << "\n";
    }

    static void display()
    {
        for (int i = 0; i < countPhone; i++)
        {
            std::cout << "Phone ID: " << list[i].id << "\n";
            std::cout << "Phone Brand: " << list[i].brand << "\n";
            std::cout << "Phone Price: " << list[i].price << "\n";
            std::cout << "----------------------" << "\n";
        }
    }
};

Phone *Phone::list = new Phone[100];
int Phone::countPhone = 0;

int main()
{
    int choice;
    std::string id, brand;
    int price;

    while (true)
    {
        std::cout << "1. Add phone" << "\n";
        std::cout << "2. Show phone info" << "\n";
        std::cout << "3. Set price" << "\n";
        std::cout << "4. Remove phone" << "\n";
        std::cout << "5. Display all phone" << "\n";
        std::cout << "6. Exit" << "\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Enter phone ID: ";
            std::cin >> id;
            std::cout << "Enter phone brand: ";
            std::cin >> brand;
            std::cout << "Enter phone price: ";
            std::cin >> price;
            Phone::addPhone(Phone(id, brand, price));
            break;
        case 2:
            std::cout << "Enter phone ID: ";
            std::cin >> id;
            Phone::showInfoPhone(id);
            break;
        case 3:
            std::cout << "Enter phone ID: ";
            std::cin >> id;
            Phone::setPrice(id);
            break;
        case 4:
            std::cout << "Enter phone ID: ";
            std::cin >> id;
            Phone::removePhone(id);
            break;
        case 5:
            Phone::display();
            break;
        case 6:
            return 0;
        default:
            std::cout << "Invalid choice." << "\n";
            break;
        }
    }
}
