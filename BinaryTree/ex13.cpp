#include <iostream>
#include <fstream>

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

void saveTree(Node *root, std::ofstream &outFile)
{
    if (root == nullptr)
    {
        int nullValue = -1;
        outFile.write((char *)&nullValue, sizeof(nullValue));
        return;
    }

    outFile.write((char *)&root->data, sizeof(root->data));
    saveTree(root->left, outFile);
    saveTree(root->right, outFile);
}

Node *loadTree(std::ifstream &inFile)
{
    int value;
    if (!inFile.read((char *)&value, sizeof(value)))
    {
        return nullptr;
    }

    if (value == -1)
    {
        return nullptr;
    }

    Node *root = new Node(value);
    root->left = loadTree(inFile);
    root->right = loadTree(inFile);

    return root;
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
    int arr[] = {10, 5, 3, 9, 7, 15, 12, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = createBinaryTree(arr, n);

    std::ofstream outFile("tree_data.dat", std::ios::binary);
    if (!outFile)
    {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    saveTree(root, outFile);
    outFile.close();
    std::cout << "The binary tree has been saved to the file 'tree_data.dat'." << std::endl;

    std::ifstream inFile("tree_data.dat", std::ios::binary);
    if (!inFile)
    {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    Node *newRoot = loadTree(inFile);
    inFile.close();

    std::cout << "The binary tree has been read from the file." << std::endl;

    deleteTree(root);
    deleteTree(newRoot);

    return 0;
}
