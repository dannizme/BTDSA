#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int value)
    {
        key = value;
        left = right = nullptr;
        height = 1;
    }
};

class AVLTree
{
private:
    Node *root;

    int height(Node *node)
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int getBalance(Node *node)
    {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node *insert(Node *node, int key)
    {
        if (node == nullptr)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        if (balance > 1 && key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node *search(Node *node, int key)
    {
        if (node == nullptr || node->key == key)
            return node;

        if (key < node->key)
            return search(node->left, key);

        return search(node->right, key);
    }

    Node *minNode(Node *node)
    {
        Node *current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    Node *deleteNode(Node *root, int key)
    {
        if (root == nullptr)
            return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else
        {
            if ((root->left == nullptr) || (root->right == nullptr))
            {
                Node *temp = root->left ? root->left : root->right;

                if (temp == nullptr)
                {
                    temp = root;
                    root = nullptr;
                }
                else
                {
                    *root = *temp;
                }
                delete temp;
            }
            else
            {
                Node *temp = minNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }

        if (root == nullptr)
            return root;

        root->height = max(height(root->left), height(root->right)) + 1;

        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        if (balance > 1 && getBalance(root->left) < 0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && getBalance(root->right) > 0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void inorder(Node *root)
    {
        if (root != nullptr)
        {
            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }
    }

public:
    AVLTree()
    {
        root = nullptr;
    }

    void insert(int key)
    {
        root = insert(root, key);
    }

    bool search(int key)
    {
        Node *node = search(root, key);
        return node != nullptr;
    }

    void deleteNode(int key)
    {
        root = deleteNode(root, key);
    }

    void inorder()
    {
        inorder(root);
        cout << endl;
    }
};

int main()
{
    AVLTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(25);
    tree.insert(5);

    cout << "In-order traversal of AVL tree: ";
    tree.inorder();

    cout << "Searching for 25: " << (tree.search(25) ? "Found" : "Not Found") << endl;

    tree.deleteNode(20);
    cout << "In-order traversal after deletion: ";
    tree.inorder();

    return 0;
}
