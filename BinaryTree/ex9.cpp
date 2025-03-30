#include <iostream>
#include <fstream>

struct Node
{
    double data;
    Node *left;
    Node *right;

    Node(double val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node *insertNode(Node *root, double value)
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

Node *createBinaryTree(double arr[], int n)
{
    Node *root = nullptr;
    for (int i = 0; i < n; ++i)
    {
        root = insertNode(root, arr[i]);
    }

    return root;
}

void preOrderTraversal(Node *root, std::ofstream &outFile)
{
    if (root == nullptr)
    {
        return;
    }

    outFile.write((char *)&root->data, sizeof(root->data));
    preOrderTraversal(root->left, outFile);
    preOrderTraversal(root->right, outFile);
}

int main()
{
    double arr[] = {20.5, 10.3, 30.7, 5.1, 15.2, 25.6, 35.4};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = createBinaryTree(arr, n);

    std::ofstream outFile("data_ex9.out", std::ios::binary);
    if (!outFile)
    {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    preOrderTraversal(root, outFile);

    outFile.close();
    std::cout << "Cây nhị phân đã được xuất ra tập tin data_ex9.out" << std::endl;

    return 0;
}
