#include <iostream>

struct NodeTree
{
    int data;
    NodeTree *left;
    NodeTree *right;

    NodeTree(int value) : data(value), left(nullptr), right(nullptr) {}
};

struct Node
{
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

NodeTree *insertNodeTree(NodeTree *root, int value)
{
    if (root == nullptr)
    {
        return new NodeTree(value);
    }

    if (value < root->data)
    {
        root->left = insertNodeTree(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insertNodeTree(root->right, value);
    }

    return root;
}

NodeTree *createBST(int arr[], int n)
{
    NodeTree *root = nullptr;
    for (int i = 0; i < n; ++i)
    {
        root = insertNodeTree(root, arr[i]);
    }

    return root;
}

void insertNode(NodeTree *root, Node *&head)
{
    if (root == nullptr)
    {
        return;
    }

    insertNode(root->left, head);

    Node *newNode = new Node(root->data);
    newNode->next = head;
    head = newNode;

    insertNode(root->right, head);
}

Node *convertBSTtoLinkedList(NodeTree *root)
{
    Node *head = nullptr;
    insertNode(root, head);
    return head;
}

void printList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main()
{
    int arr[] = {10, 5, 3, 9, 7, 15, 12, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    NodeTree *root = createBST(arr, n);
    Node *head = convertBSTtoLinkedList(root);

    printList(head);

    return 0;
}