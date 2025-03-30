#include <iostream>

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node *insertNode(Node *root, int value)
{
    if (root == nullptr)
    {
        return new Node(value);
    }

    if (value < root->data)
    {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insertNode(root->right, value);
    }

    return root;
}

void preOrderWithoutRecursion(Node *root)
{
    if (root == nullptr)
        return;

    Node *stack[100];
    int top = -1;
    stack[++top] = root;

    while (top != -1)
    {
        Node *currentNode = stack[top--];
        std::cout << currentNode->data << " ";

        if (currentNode->right)
        {
            stack[++top] = currentNode->right;
        }
        if (currentNode->left)
        {
            stack[++top] = currentNode->left;
        }
    }
}

int main()
{
    int arr[] = {10, 5, 3, 9, 7, 15, 12, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = nullptr;

    for (int i = 0; i < n; ++i)
    {
        root = insertNode(root, arr[i]);
    }

    std::cout << "Pre-order traversal without recursion: ";
    preOrderWithoutRecursion(root);
    std::cout << std::endl;

    return 0;
}
