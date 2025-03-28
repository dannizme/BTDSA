#include <iostream>
#include <string>

struct SinhVien
{
    std::string hoTen;
    std::string diaChi;
    std::string lop;
    int khoa;

    SinhVien() {}
    SinhVien(const std::string &ht, const std::string &dc, const std::string &l, int k)
        : hoTen(ht), diaChi(dc), lop(l), khoa(k) {}
};

struct Node
{
    SinhVien data;
    Node *next;
    Node(SinhVien sv) : data(sv), next(nullptr) {}
};

bool compareByName(SinhVien sv1, SinhVien sv2)
{
    return sv1.hoTen < sv2.hoTen;
}

bool compareByAddress(SinhVien sv1, SinhVien sv2)
{
    return sv1.diaChi < sv2.diaChi;
}

bool compareByClass(SinhVien sv1, SinhVien sv2)
{
    return sv1.lop < sv2.lop;
}

bool compareByYear(SinhVien sv1, SinhVien sv2)
{
    return sv1.khoa < sv2.khoa;
}

void inputStudent(SinhVien &sv)
{
    std::cin.ignore();
    std::cout << "Enter name: ";
    std::getline(std::cin, sv.hoTen);
    std::cout << "Enter address: ";
    std::getline(std::cin, sv.diaChi);
    std::cout << "Enter class: ";
    std::getline(std::cin, sv.lop);
    std::cout << "Enter year: ";
    std::cin >> sv.khoa;
}

void outputStudent(SinhVien sv)
{
    std::cout << "Name: " << sv.hoTen << ", Address: " << sv.diaChi
              << ", Class: " << sv.lop << ", Year: " << sv.khoa << "\n";
}

class ListSV
{
private:
    Node *head;

public:
    ListSV() : head(nullptr) {}
    ~ListSV()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void add(SinhVien sv)
    {
        Node *newNode = new Node(sv);
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

    void removeByName(const std::string &name)
    {
        if (head == nullptr)
            return;
        if (head->data.hoTen == name)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *current = head;
        while (current->next != nullptr && current->next->data.hoTen != name)
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

    void removeByAddress(const std::string &address)
    {
        if (head == nullptr)
            return;
        if (head->data.diaChi == address)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *current = head;
        while (current->next != nullptr && current->next->data.diaChi != address)
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

    void appendList(ListSV &other)
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
            outputStudent(current->data);
            current = current->next;
        }
    }

    void sort(bool (*compare)(SinhVien, SinhVien))
    {
        if (head == nullptr || head->next == nullptr)
            return;
        Node *current = head;
        while (current != nullptr)
        {
            Node *minNode = current;
            Node *next = current->next;
            while (next != nullptr)
            {
                if (!compare(minNode->data, next->data))
                {
                    minNode = next;
                }
                next = next->next;
            }
            if (minNode != current)
            {
                SinhVien temp = current->data;
                current->data = minNode->data;
                minNode->data = temp;
            }
            current = current->next;
        }
    }
};

int main()
{
    ListSV list;
    for (int i = 0; i < 10; i++)
    {
        SinhVien sv;
        std::cout << "Enter student " << i + 1 << ":\n";
        inputStudent(sv);
        list.add(sv);
    }
    std::cout << "Initial list:\n";
    list.print();

    list.removeByName("Nguyen Van Teo");
    list.removeByAddress("Nguyen Van Cu");
    std::cout << "List after removing:\n";
    list.print();

    SinhVien newSV("Tran Thi Mo", "25 Hong Bang", "TT0901", 2009);
    list.add(newSV);
    std::cout << "List after adding new student:\n";
    list.print();

    return 0;
}