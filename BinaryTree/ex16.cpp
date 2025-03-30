#include <iostream>

struct Node
{
    int data;
    int count;
    Node *left;
    Node *right;

    Node(int value) : data(value), count(1), left(nullptr), right(nullptr) {}
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
    else
    {
        root->count++;
    }

    return root;
}

Node *search(Node *root, int value)
{
    if (root == nullptr || root->data == value)
    {
        return root;
    }

    if (value < root->data)
    {
        return search(root->left, value);
    }
    else
    {
        return search(root->right, value);
    }
}

void deleteNode(Node *&root, int value)
{
    Node *foundNode = search(root, value);
    if (foundNode != nullptr)
    {
        foundNode->count--;
        if (foundNode->count == 0)
        {
            std::cout << "Node with value " << value << " is completely removed from the tree." << std::endl;
        }
        else
        {
            std::cout << "Decremented count for node with value " << value << " to " << foundNode->count << std::endl;
        }
    }
    else
    {
        std::cout << "Element " << value << " not found in the tree." << std::endl;
    }
}

void preOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    std::cout << "Value: " << root->data << ", Count: " << root->count << std::endl;
    preOrder(root->left);
    preOrder(root->right);
}

void deleteTree(Node *root)
{
    if (root == nullptr)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main()
{
    Node *root = nullptr;
    int arr[] = {10, 5, 3, 9, 7, 15, 12, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; ++i)
    {
        root = insertNode(root, arr[i]);
    }

    std::cout << "Binary Tree (Pre-order):" << std::endl;
    preOrder(root);

    std::cout << std::endl;
    int valueToDelete = 10;
    std::cout << "Deleting node with value " << valueToDelete << ":" << std::endl;
    deleteNode(root, valueToDelete);

    std::cout << "Binary Tree after deletion:" << std::endl;
    preOrder(root);

    deleteTree(root); // Clean up memory
    root = nullptr;   // Set root to nullptr after deletion
    return 0;
}