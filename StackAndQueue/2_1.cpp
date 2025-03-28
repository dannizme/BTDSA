#include <iostream>
#include <string>

#define MAX 100

class StackInt
{
private:
    int arr[MAX];
    int top;

public:
    StackInt()
    {
        top = -1;
    }

    void InitStack()
    {
        top = -1;
    }

    bool IsEmpty()
    {
        return top == -1;
    }

    bool IsFull()
    {
        return top == MAX - 1;
    }

    void Push(int value)
    {
        if (IsFull())
        {
            std::cout << "Stack is full!" << std::endl;
        }
        else
        {
            arr[++top] = value;
        }
    }

    int Pop()
    {
        if (IsEmpty())
        {
            std::cout << "Stack is empty!" << std::endl;
            return -1;
        }
        else
        {
            return arr[top--];
        }
    }

    int Peek()
    {
        if (IsEmpty())
        {
            std::cout << "Stack is empty!" << std::endl;
            return -1;
        }
        else
        {
            return arr[top];
        }
    }

    void Clear()
    {
        top = -1;
    }
};

class StackString
{
private:
    char *arr;
    int top;
    int capacity;

public:
    StackString(int size)
    {
        capacity = size;
        arr = new char[capacity];
        top = -1;
    }

    ~StackString()
    {
        delete[] arr;
    }

    void InitStack()
    {
        top = -1;
    }

    bool IsEmpty()
    {
        return top == -1;
    }

    bool IsFull()
    {
        return top == capacity - 1;
    }

    void Push(char value)
    {
        if (IsFull())
        {
            std::cout << "Stack is full!" << std::endl;
        }
        else
        {
            arr[++top] = value;
        }
    }

    char Pop()
    {
        if (IsEmpty())
        {
            std::cout << "Stack is empty!" << std::endl;
            return '\0';
        }
        else
        {
            return arr[top--];
        }
    }

    char Peek()
    {
        if (IsEmpty())
        {
            std::cout << "Stack is empty!" << std::endl;
            return '\0';
        }
        else
        {
            return arr[top];
        }
    }

    void Clear()
    {
        top = -1;
    }
};

class Node
{
public:
    int data;
    Node *next;
};

class LinkedStackInt
{
private:
    Node *top;

public:
    LinkedStackInt()
    {
        top = nullptr;
    }

    void InitStack()
    {
        top = nullptr;
    }

    bool IsEmpty()
    {
        return top == nullptr;
    }

    void Push(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    int Pop()
    {
        if (IsEmpty())
        {
            std::cout << "Stack is empty!" << std::endl;
            return -1;
        }
        else
        {
            Node *temp = top;
            int value = top->data;
            top = top->next;
            delete temp;
            return value;
        }
    }

    int Peek()
    {
        if (IsEmpty())
        {
            std::cout << "Stack is empty!" << std::endl;
            return -1;
        }
        else
        {
            return top->data;
        }
    }

    void Clear()
    {
        while (!IsEmpty())
        {
            Pop();
        }
    }
};

void ReverseNumber(int num)
{
    StackInt stack;
    while (num > 0)
    {
        stack.Push(num % 10);
        num /= 10;
    }
    while (!stack.IsEmpty())
    {
        std::cout << stack.Pop();
    }
}

bool IsPalindrome(const std::string &str)
{
    StackString stack(str.length());

    for (char c : str)
    {
        stack.Push(c);
    }

    for (char c : str)
    {
        if (c != stack.Pop())
        {
            return false;
        }
    }

    return true;
}

void DecimalToBinary(int num)
{
    StackInt stack;
    while (num > 0)
    {
        stack.Push(num % 2);
        num /= 2;
    }
    while (!stack.IsEmpty())
    {
        std::cout << stack.Pop();
    }
}

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

std::string InfixToPostfix(const std::string &infix)
{
    StackString opStack(infix.length());
    std::string postfix;

    for (char c : infix)
    {
        if (isDigit(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            opStack.Push(c);
        }
        else if (c == ')')
        {
            while (!opStack.IsEmpty() && opStack.Peek() != '(')
            {
                postfix += opStack.Pop();
            }
            opStack.Pop(); // Remove '('
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            while (!opStack.IsEmpty() && precedence(opStack.Peek()) >= precedence(c))
            {
                postfix += opStack.Pop();
            }
            opStack.Push(c);
        }
    }

    while (!opStack.IsEmpty())
    {
        postfix += opStack.Pop();
    }

    return postfix;
}

int evaluatePostfix(const std::string &postfix)
{
    StackInt stack;

    for (char c : postfix)
    {
        if (isDigit(c))
        {
            stack.Push(c - '0');
        }
        else
        {
            int b = stack.Pop();
            int a = stack.Pop();
            int result = applyOperator(a, b, c);
            stack.Push(result);
        }
    }
    return stack.Pop();
}

int applyOperator(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        return 0;
    }
}

int main()
{
    std::string infix;
    std::cout << "Enter an infix expression: ";
    std::cin >> infix;

    std::string postfix = InfixToPostfix(infix);
    std::cout << "Postfix expression: " << postfix << std::endl;

    int result = evaluatePostfix(postfix);
    std::cout << "Evaluation result: " << result << std::endl;

    int num = 12345;
    std::cout << "Reversed number: ";
    ReverseNumber(num);
    std::cout << std::endl;

    std::string str = "racecar";
    std::cout << "Is palindrome: " << (IsPalindrome(str) ? "Yes" : "No") << std::endl;

    num = 29;
    std::cout << "Binary of " << num << ": ";
    DecimalToBinary(num);
    std::cout << std::endl;

    return 0;
}
