#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

class ListInt
{
private:
    Node *head;

public:
    ListInt() : head(nullptr) {}
    ~ListInt()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void add(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
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

    void remove(int value)
    {
        if (head == nullptr)
            return;
        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *current = head;
        while (current->next != nullptr && current->next->data != value)
        {
            current = current->next;
        }
        if (current->next != nullptr)
        {
            Node *temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    void appendList(ListInt &other)
    {
        if (other.head == nullptr)
            return;
        Node *newHead = new Node(other.head->data);
        Node *current = newHead;
        Node *otherCurrent = other.head->next;
        while (otherCurrent != nullptr)
        {
            current->next = new Node(otherCurrent->data);
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
        if (head == nullptr)
        {
            head = newHead;
        }
        else
        {
            current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newHead;
        }
    }

    void print()
    {
        Node *current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }
};

int main()
{
    ListInt list1;
    for (int i = 0; i < 10; i++)
    {
        int value;
        std::cin >> value;
        list1.add(value);
    }
    std::cout << "Initial list: ";
    list1.print();

    int k;
    std::cout << "Enter number to remove: ";
    std::cin >> k;
    list1.remove(k);
    std::cout << "List after removing " << k << ": ";
    list1.print();

    ListInt list2;
    for (int i = 0; i < 5; i++)
    {
        int value;
        std::cin >> value;
        list2.add(value);
    }
    list1.appendList(list2);
    std::cout << "List after appending second list: ";
    list1.print();

    return 0;
}