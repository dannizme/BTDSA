#include <iostream>
#include <string>

class Book
{
private:
    std::string title;
    std::string id;
    int price;

public:
    std::string getTitle()
    {
        return title;
    }
    void setTitle(std::string title)
    {
        this->title = title;
    }

    std::string getID()
    {
        return id;
    }
    void setID(std::string id)
    {
        this->id = id;
    }

    int getPrice()
    {
        return price;
    }
    void setPrice(int price)
    {
        this->price = price;
    }

    void displayInfo()
    {
        std::cout << "Title: " << title << "\n";
        std::cout << "ID: " << id << "\n";
        std::cout << "Price: " << price << "\n";
    }
};

void inputOneBook(Book &book)
{
    std::string title, id;
    int price;

    std::cout << "Enter title: ";
    std::cin.ignore(); // Clear buffer
    std::getline(std::cin, title);

    std::cout << "Enter ID: ";
    std::getline(std::cin, id);

    std::cout << "Enter price: ";
    std::cin >> price;

    book.setTitle(title);
    book.setID(id);
    book.setPrice(price);
}

void inputBookArray(Book books[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter book " << i + 1 << "\n";
        inputOneBook(books[i]);
    }
}

bool searchBookByID(Book books[], int n, const std::string &id)
{
    for (int i = 0; i < n; i++)
    {
        if (books[i].getID() == id)
        {
            return true;
        }
    }
    return false;
}

// Search by Book Title
bool searchBookByTitle(Book books[], int n, const std::string &title)
{
    std::string lowerTitle = title;
    for (char &c : lowerTitle)
    {
        c = tolower(c);
    }

    for (int i = 0; i < n; i++)
    {
        std::string bookTitle = books[i].getTitle();
        for (char &c : bookTitle)
        {
            c = tolower(c);
        }
        if (bookTitle == lowerTitle)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    std::cout << "Enter number of books: ";
    std::cin >> n;
    Book books[n];

    inputBookArray(books, n);

    std::string searchID;
    std::cout << "Enter ID to search: ";
    std::cin >> searchID;
    if (searchBookByID(books, n, searchID))
    {
        std::cout << "Book found by ID!\n";
    }
    else
    {
        std::cout << "Book not found by ID.\n";
    }

    std::string searchTitle;
    std::cout << "Enter title to search: ";
    std::cin.ignore(); // Clear buffer
    std::getline(std::cin, searchTitle);
    if (searchBookByTitle(books, n, searchTitle))
    {
        std::cout << "Book found by title!\n";
    }
    else
    {
        std::cout << "Book not found by title.\n";
    }

    return 0;
}
