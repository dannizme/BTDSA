#include <iostream>
#include <string>

struct node
{
    std::string data;
    node *next;
};

struct list
{
    node *head, *tail;
};

node *getNode(std::string value)
{
    node *p = new node;
    if (p == nullptr)
    {
        exit(1);
    }

    p->data = value;
    p->next = nullptr;

    return p;
}

int main()
{
    node *head = getNode("Hello World");
    std::cout << head->data << "\n";
    delete head;

    return 0;
}