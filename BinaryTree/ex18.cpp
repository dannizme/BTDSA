#include <iostream>

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

TreeNode *insert(TreeNode *root, int data)
{
    if (root == nullptr)
    {
        return new TreeNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

TreeNode *createBSTFromArray(const int a[], int n)
{
    TreeNode *root = nullptr;
    for (int i = 0; i < n; i++)
    {
        root = insert(root, a[i]);
    }
    return root;
}

void inorder(TreeNode *root, int result[], int &index)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left, result, index);
    result[index++] = root->data;
    inorder(root->right, result, index);
}

int main()
{
    int a[] = {10, 5, 3, 9, 7, 15, 12, 18, 20};
    int n = sizeof(a) / sizeof(a[0]);
    TreeNode *root = createBSTFromArray(a, n);

    int result[n];
    int index = 0;
    inorder(root, result, index);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
