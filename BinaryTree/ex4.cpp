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

Node *findMin(Node *root)
{
    while (root != nullptr && root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

Node *findMax(Node *root)
{
    while (root != nullptr && root->right != nullptr)
    {
        root = root->right;
    }
    return root;
}

int main()
{
    int arr[] = {10, 5, 3, 9, 7, 15, 12, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = createBinaryTree(arr, n);

    Node *minNode = findMin(root);
    Node *maxNode = findMax(root);

    if (minNode != nullptr)
    {
        std::cout << "Minimum value in the tree: " << minNode->data << std::endl;
    }
    else
    {
        std::cout << "Tree is empty." << std::endl;
    }

    if (maxNode != nullptr)
    {
        std::cout << "Maximum value in the tree: " << maxNode->data << std::endl;
    }
    else
    {
        std::cout << "Tree is empty." << std::endl;
    }

    return 0;
}