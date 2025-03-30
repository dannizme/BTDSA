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

Node *findMin(Node *root)
{
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

Node *deleteNode(Node *root, int value)
{
    if (root == nullptr)
    {
        return root;
    }

    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
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

int main()
{
    int arr[] = {10, 5, 3, 9, 7, 15, 12, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = nullptr;

    for (int i = 0; i < n; ++i)
    {
        root = insertNode(root, arr[i]);
    }

    std::cout << "Tree before deletion:" << std::endl;
    preOrder(root);

    int valueToDelete = 10;
    root = deleteNode(root, valueToDelete);

    std::cout << "\nTree after deletion:" << std::endl;
    preOrder(root);

    return 0;
}
