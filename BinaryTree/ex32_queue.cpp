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

void levelOrderWithoutRecursion(Node *root)
{
    if (root == nullptr)
        return;

    Node *queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear)
    {
        Node *currentNode = queue[front++];
        std::cout << currentNode->data << " ";

        if (currentNode->left)
        {
            queue[rear++] = currentNode->left;
        }
        if (currentNode->right)
        {
            queue[rear++] = currentNode->right;
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

    std::cout << "Level-order traversal without recursion: ";
    levelOrderWithoutRecursion(root);
    std::cout << std::endl;

    return 0;
}
