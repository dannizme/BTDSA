#include <iostream>
#include <string>
#include <cmath>

class QueueInt
{
private:
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    QueueInt(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }

    void EnQueue(int value)
    {
        if (isFull())
        {
            std::cout << "Queue is Full!" << std::endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    int DeQueue()
    {
        if (isEmpty())
        {
            std::cout << "Queue is Empty!" << std::endl;
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    int Peak()
    {
        if (isEmpty())
        {
            std::cout << "Queue is Empty!" << std::endl;
            return -1;
        }
        return arr[front];
    }

    void Clear()
    {
        front = 0;
        rear = -1;
        size = 0;
    }

    ~QueueInt()
    {
        delete[] arr;
    }
};

struct Node
{
    int data;
    Node *next;
};

class LinkedQueueInt
{
private:
    Node *front;
    Node *rear;

public:
    LinkedQueueInt()
    {
        front = nullptr;
        rear = nullptr;
    }

    bool IsEmpty()
    {
        return front == nullptr;
    }

    void Enqueue(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (IsEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int Dequeue()
    {
        if (IsEmpty())
        {
            std::cout << "Queue is empty!" << std::endl;
            return -1;
        }
        Node *temp = front;
        int value = front->data;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        delete temp;
        return value;
    }

    int Peek()
    {
        if (IsEmpty())
        {
            std::cout << "Queue is empty!" << std::endl;
            return -1;
        }
        return front->data;
    }

    void Clear()
    {
        while (!IsEmpty())
        {
            Dequeue();
        }
    }

    ~LinkedQueueInt()
    {
        Clear();
    }
};

struct Dancer
{
    std::string Name;
    std::string Sex;
};

class QueueDancer
{
private:
    Dancer *arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    QueueDancer(int cap = 10)
    {
        capacity = cap;
        arr = new Dancer[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    QueueDancer(const QueueDancer &other)
    {
        capacity = other.capacity;
        size = other.size;
        front = other.front;
        rear = other.rear;
        arr = new Dancer[capacity];
        for (int i = 0; i < capacity; i++)
        {
            arr[i] = other.arr[i];
        }
    }

    bool IsEmpty()
    {
        return size == 0;
    }

    bool IsFull()
    {
        return size == capacity;
    }

    void Enqueue(Dancer value)
    {
        if (IsFull())
        {
            std::cout << "Queue is full!" << std::endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    Dancer Dequeue()
    {
        if (IsEmpty())
        {
            std::cout << "Queue is empty!" << std::endl;
            return {"", ""};
        }
        Dancer value = arr[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    Dancer Peek()
    {
        if (IsEmpty())
        {
            std::cout << "Queue is empty!" << std::endl;
            return {"", ""};
        }
        return arr[front];
    }

    void Clear()
    {
        front = 0;
        rear = -1;
        size = 0;
    }

    int GetSize()
    {
        return size;
    }

    void ShowQueue()
    {
        if (IsEmpty())
        {
            std::cout << "Queue is empty!" << std::endl;
            return;
        }
        int index = front;
        for (int i = 0; i < size; i++)
        {
            std::cout << arr[index].Name << std::endl;
            index = (index + 1) % capacity;
        }
    }

    ~QueueDancer()
    {
        delete[] arr;
    }
};

int getMaxDigits(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max == 0 ? 1 : static_cast<int>(log10(max)) + 1;
}

int getDigit(int num, int pos)
{
    return (num / static_cast<int>(pow(10, pos))) % 10;
}

void RadixSort(int arr[], int n)
{
    QueueInt *queues[10];
    for (int i = 0; i < 10; i++)
    {
        queues[i] = new QueueInt(n);
    }

    int maxDigits = getMaxDigits(arr, n);

    for (int pos = 0; pos < maxDigits; pos++)
    {
        for (int i = 0; i < n; i++)
        {
            int digit = getDigit(arr[i], pos);
            queues[digit]->EnQueue(arr[i]);
        }

        int index = 0;
        for (int digit = 0; digit < 10; digit++)
        {
            while (!queues[digit]->isEmpty())
            {
                arr[index++] = queues[digit]->DeQueue();
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        delete queues[i];
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void NewDancers(QueueDancer &male, QueueDancer &female)
{
    if (!male.IsEmpty() && !female.IsEmpty())
    {
        Dancer m = male.Dequeue();
        Dancer w = female.Dequeue();
        std::cout << "Cap dien vien: " << m.Name << " va " << w.Name << std::endl;
    }
    else if (!male.IsEmpty() && female.IsEmpty())
    {
        std::cout << "Dang cho dien vien nu." << std::endl;
    }
    else if (!female.IsEmpty() && male.IsEmpty())
    {
        std::cout << "Dang cho dien vien nam." << std::endl;
    }
}

void HeadOfLine(QueueDancer &male, QueueDancer &female)
{
    if (!male.IsEmpty() && !female.IsEmpty())
    {
        Dancer m = male.Peek();
        Dancer w = female.Peek();
        std::cout << "Cap dien vien ke tiep: " << m.Name << "\t" << w.Name << std::endl;
    }
    else if (!male.IsEmpty())
    {
        Dancer m = male.Peek();
        std::cout << "Dien vien nam ke tiep: " << m.Name << std::endl;
    }
    else if (!female.IsEmpty())
    {
        Dancer w = female.Peek();
        std::cout << "Dien vien nu ke tiep: " << w.Name << std::endl;
    }
}

void StartDancing(QueueDancer &male, QueueDancer &female)
{
    std::cout << "Cac cap dien vien:" << std::endl;
    while (!male.IsEmpty() && !female.IsEmpty())
    {
        Dancer m = male.Dequeue();
        Dancer w = female.Dequeue();
        std::cout << m.Name << "\t" << w.Name << std::endl;
    }
    if (!male.IsEmpty())
    {
        std::cout << "Con " << male.GetSize() << " dien vien nam dang cho.\n";
    }
    if (!female.IsEmpty())
    {
        std::cout << "Con " << female.GetSize() << " dien vien nu dang cho.\n";
    }
}

void FormLines(QueueDancer &male, QueueDancer &female)
{
    std::string dancers[] = {"F Trang", "M Truc", "M Thien", "M Bao", "F Thu", "M Tien",
                             "F Thuy", "M Nghia", "F Thao", "M Phuoc", "M Hung", "F Vy"};

    int n = sizeof(dancers) / sizeof(dancers[0]);

    for (int i = 0; i < n; i++)
    {
        Dancer d;
        std::string person = dancers[i];
        d.Sex = person.substr(0, 1);
        d.Name = person.substr(2);

        if (d.Sex == "M")
        {
            male.Enqueue(d);
        }
        else
        {
            female.Enqueue(d);
        }
    }
}

int main()
{
    std::cout << "Testing QueueInt (Array-based Queue)\n";
    QueueInt intQueue(5);
    intQueue.EnQueue(10);
    intQueue.EnQueue(20);
    intQueue.EnQueue(30);
    std::cout << "Front element: " << intQueue.Peak() << std::endl;
    std::cout << "Dequeued: " << intQueue.DeQueue() << std::endl;
    std::cout << "Dequeued: " << intQueue.DeQueue() << std::endl;

    std::cout << "\nTesting LinkedQueueInt (Linked List-based Queue)\n";
    LinkedQueueInt linkedQueue;
    linkedQueue.Enqueue(100);
    linkedQueue.Enqueue(200);
    std::cout << "Front element: " << linkedQueue.Peek() << std::endl;
    std::cout << "Dequeued: " << linkedQueue.Dequeue() << std::endl;

    std::cout << "\nTesting Radix Sort with QueueInt\n";
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Original array: ";
    printArray(arr, n);
    RadixSort(arr, n);
    std::cout << "Sorted array: ";
    printArray(arr, n);

    std::cout << "\nTesting QueueDancer (Pairing System)\n";
    QueueDancer maleQueue, femaleQueue;
    FormLines(maleQueue, femaleQueue);

    std::cout << "\n--- Male Dancers ---\n";
    maleQueue.ShowQueue();

    std::cout << "\n--- Female Dancers ---\n";
    femaleQueue.ShowQueue();

    std::cout << "\nPairing Dancers...\n";
    StartDancing(maleQueue, femaleQueue);

    return 0;
}