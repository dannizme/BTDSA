#include <iostream>
#include <string>

template <typename T>
class Stack
{
private:
    T *arr;
    int capacity;
    int topIndex;

public:
    Stack(int size = 100)
    {
        capacity = size;
        arr = new T[capacity];
        topIndex = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return topIndex == -1;
    }

    bool isFull()
    {
        return topIndex == capacity - 1;
    }

    void push(T value)
    {
        if (isFull())
        {
            std::cout << "Stack is full!\n";
            return;
        }
        arr[++topIndex] = value;
    }

    T pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty!\n";
            return T();
        }
        return arr[topIndex--];
    }

    T top()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty!\n";
            return T();
        }
        return arr[topIndex];
    }
};

long long FibonacciRecursive(int n)
{
    if (n <= 1)
        return n;
    return FibonacciRecursive(n - 1) + FibonacciRecursive(n - 2);
}

long long FibonacciIterativeWithStack(int n)
{
    if (n <= 1)
        return n;

    Stack<std::pair<int, long long>> stk;
    stk.push({n, 0});
    long long result = 0;

    while (!stk.isEmpty())
    {
        auto current = stk.pop();
        int currentN = current.first;
        long long value = current.second;

        if (currentN <= 1)
        {
            result += currentN;
            continue;
        }

        if (value == 0)
        {
            stk.push({currentN, 1});
            stk.push({currentN - 1, 0});
        }
        else
        {
            stk.push({currentN - 2, 0});
        }
    }

    return result;
}

int ReverseNumberRecursive(int num, int reversed = 0)
{
    if (num == 0)
        return reversed;
    int digit = num % 10;
    return ReverseNumberRecursive(num / 10, reversed * 10 + digit);
}

int ReverseNumberWithStack(int num)
{
    Stack<int> digits;
    while (num > 0)
    {
        digits.push(num % 10);
        num /= 10;
    }

    int reversed = 0;
    int place = 1;
    while (!digits.isEmpty())
    {
        reversed += digits.top() * place;
        digits.pop();
        place *= 10;
    }
    return reversed;
}

void HanoiTowerRecursive(int n, char source, char auxiliary, char destination)
{
    if (n == 1)
    {
        std::cout << "Move disk 1 from " << source << " to " << destination << "\n";
        return;
    }
    HanoiTowerRecursive(n - 1, source, destination, auxiliary);
    std::cout << "Move disk " << n << " from " << source << " to " << destination << "\n";
    HanoiTowerRecursive(n - 1, auxiliary, source, destination);
}

void HanoiTowerWithStack(int n, char source, char auxiliary, char destination)
{
    struct Move
    {
        int numDisks;
        char src, aux, dest;
        int state;
    };

    Stack<Move> stk;
    stk.push({n, source, auxiliary, destination, 0});

    while (!stk.isEmpty())
    {
        Move current = stk.pop();

        if (current.numDisks == 1)
        {
            std::cout << "Move disk 1 from " << current.src << " to " << current.dest << "\n";
            continue;
        }

        if (current.state == 0)
        {
            stk.push({current.numDisks, current.src, current.aux, current.dest, 1});
            stk.push({current.numDisks - 1, current.src, current.dest, current.aux, 0});
        }
        else if (current.state == 1)
        {
            std::cout << "Move disk " << current.numDisks << " from " << current.src << " to " << current.dest << "\n";
            stk.push({current.numDisks, current.src, current.aux, current.dest, 2});
        }
        else
        {
            stk.push({current.numDisks - 1, current.aux, current.src, current.dest, 0});
        }
    }
}

int main()
{
    std::cout << "Testing Fibonacci\n";
    for (int i = 0; i <= 10; i++)
    {
        std::cout << "Fibonacci(" << i << ") = " << FibonacciRecursive(i) << " (Recursive)\n";
        std::cout << "Fibonacci(" << i << ") = " << FibonacciIterativeWithStack(i) << " (Stack)\n";
    }

    std::cout << "\nTesting Reverse Number\n";
    int numbers[] = {12345, 100, 54321, 0};
    for (int num : numbers)
    {
        std::cout << "Original: " << num << ", Reversed (Recursive): " << ReverseNumberRecursive(num) << "\n";
        std::cout << "Original: " << num << ", Reversed (Stack): " << ReverseNumberWithStack(num) << "\n";
    }

    std::cout << "\nTesting Hanoi Tower (Recursive) with 3 disks\n";
    HanoiTowerRecursive(3, 'A', 'B', 'C');

    std::cout << "\nTesting Hanoi Tower (Stack) with 3 disks\n";
    HanoiTowerWithStack(3, 'A', 'B', 'C');

    return 0;
}