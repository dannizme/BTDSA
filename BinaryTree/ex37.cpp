#include <iostream>

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

int max(int a, int b)
{
    return (a > b) ? a : b; // Manually computing max
}

int getHeight(Node *p)
{
    if (p == nullptr)
        return 0;

    int leftHeight = getHeight(p->left);
    int rightHeight = getHeight(p->right);

    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(Node *root)
{
    if (root == nullptr)
        return true;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    if (std::abs(leftHeight - rightHeight) > 1)
    {
        return false;
    }

    return isBalanced(root->left) && isBalanced(root->right);
}

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

int main()
{
    int arr[] = {10, 5, 3, 9, 7, 15, 12, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = nullptr;

    for (int i = 0; i < n; ++i)
    {
        root = insertNode(root, arr[i]);
    }

    if (isBalanced(root))
    {
        std::cout << "The tree is balanced." << std::endl;
    }
    else
    {
        std::cout << "The tree is not balanced." << std::endl;
    }

    return 0;
}
