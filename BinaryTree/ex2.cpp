#include <iostream>

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

void modifyNode(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    temp = root->left->left;
    root->left->left = root->left->right;
    root->left->right = temp;
}

Node *createBinaryTree()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(9);
    root->right->left = new Node(12);
    root->right->right = new Node(18);
    root->right->right->left = new Node(20);
    root->left->right->left = new Node(7);
    return root;
}

void printTree(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    std::cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    Node *root = createBinaryTree();
    std::cout << "Original tree: ";
    printTree(root);
    std::cout << std::endl;

    modifyNode(root);

    std::cout << "Modified tree: ";
    printTree(root);
    std::cout << std::endl;

    return 0;
}