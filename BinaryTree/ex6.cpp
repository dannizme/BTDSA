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

Node *createBinaryTree(int arr[], int n)
{
    Node *root = nullptr;
    for (int i = 0; i < n; ++i)
    {
        root = insertNode(root, arr[i]);
    }

    return root;
}

int countNodes(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int sumValues(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return root->data + sumValues(root->left) + sumValues(root->right);
}

int main()
{
    int arr[] = {10, 5, 3, 9, 7, 15, 12, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = createBinaryTree(arr, n);

    std::cout << "Total nodes: " << countNodes(root) << std::endl;
    std::cout << "Sum of values: " << sumValues(root) << std::endl;

    return 0;
}