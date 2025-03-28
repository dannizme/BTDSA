#include <iostream>
#include <string>

struct Node
{
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList()
    {
        clear();
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void insert(int value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            head = newNode;
            return;
        }
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    bool search(int value)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void remove(int value)
    {
        if (isEmpty())
        {
            std::cout << "List is empty, nothing to remove.\n";
            return;
        }

        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            std::cout << "Removed " << value << " from the list.\n";
            return;
        }

        Node *current = head;
        while (current->next != nullptr && current->next->data != value)
        {
            current = current->next;
        }
        if (current->next == nullptr)
        {
            std::cout << "Value " << value << " not found in the list.\n";
            return;
        }

        Node *temp = current->next;
        current->next = temp->next;
        delete temp;
        std::cout << "Removed " << value << " from the list.\n";
    }

    int retrieve(int value)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                return current->data;
            }
            current = current->next;
        }
        std::cout << "Value " << value << " not found in the list.\n";
        return -1;
    }

    void traverse()
    {
        if (isEmpty())
        {
            std::cout << "List is empty.\n";
            return;
        }
        Node *current = head;
        std::cout << "List: ";
        while (current != nullptr)
        {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr\n";
    }

    void clear()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        std::cout << "List has been cleared.\n";
    }

    void sort()
    {
        if (isEmpty() || head->next == nullptr)
        {
            return;
        }

        bool swapped;
        Node *current;
        Node *last = nullptr;

        do
        {
            swapped = false;
            current = head;

            while (current->next != last)
            {
                if (current->data > current->next->data)
                {
                    int temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                    swapped = true;
                }
                current = current->next;
            }
            last = current;
        } while (swapped);

        std::cout << "List has been sorted in ascending order.\n";
    }
};

int main()
{
    LinkedList list;

    std::cout << "Is list empty? " << (list.isEmpty() ? "Yes" : "No") << "\n";

    list.insert(30);
    list.insert(10);
    list.insert(50);
    list.insert(20);
    std::cout << "After inserting 30, 10, 50, 20:\n";
    list.traverse();

    int searchValue = 50;
    std::cout << "Search for " << searchValue << ": "
              << (list.search(searchValue) ? "Found" : "Not found") << "\n";

    int retrievedValue = list.retrieve(10);
    std::cout << "Retrieved value for 10: " << retrievedValue << "\n";

    list.remove(50);
    std::cout << "After removing 50:\n";
    list.traverse();

    list.sort();
    std::cout << "After sorting:\n";
    list.traverse();

    list.clear();
    std::cout << "Is list empty after clear? " << (list.isEmpty() ? "Yes" : "No") << "\n";

    return 0;
}