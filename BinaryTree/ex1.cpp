#include <iostream>

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node *createBinaryTree(int arr[], int n, int index)
{
    if (index >= n)
    {
        return nullptr;
    }

    Node *root = new Node(arr[index]);

    root->left = createBinaryTree(arr, n, index * 2 + 1);
    root->right = createBinaryTree(arr, n, index * 2 + 2);

    return root;
}

double averageNodeValue(Node *root, int &count, int &sum)
{
    if (root == nullptr)
    {
        return 0;
    }

    sum += root->data;
    count++;

    averageNodeValue(root->left, count, sum);
    averageNodeValue(root->right, count, sum);

    return (double)sum / count;
}

double averagePositiveNodeValue(Node *root, int &count, int &sum)
{
    if (root == nullptr)
    {
        return 0;
    }

    if (root->data > 0)
    {
        sum += root->data;
        count++;
    }

    averagePositiveNodeValue(root->left, count, sum);
    averagePositiveNodeValue(root->right, count, sum);

    return (double)sum / count;
}

double averageNegativeNodeValue(Node *root, int &count, int &sum)
{
    if (root == nullptr)
    {
        return 0;
    }

    if (root->data < 0)
    {
        sum += root->data;
        count++;
    }

    averageNegativeNodeValue(root->left, count, sum);
    averageNegativeNodeValue(root->right, count, sum);

    return (double)sum / count;
}

double ratioPosToNeg(Node *root, int &sumPos, int &sumNeg)
{

    if (root == nullptr)
    {
        return 0;
    }

    if (root->data > 0)
    {
        sumPos += root->data;
    }
    if (root->data < 0)
    {
        sumNeg += root->data;
    }

    ratioPosToNeg(root->left, sumPos, sumNeg);
    ratioPosToNeg(root->right, sumPos, sumNeg);

    return (sumNeg != 0) ? (double)sumPos / sumNeg : 0;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, -12, -13, 14};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = createBinaryTree(arr, n, 0);

    int count = 0, sum = 0;
    double avgAll = averageNodeValue(root, count, sum);
    std::cout << "Average value of all nodes in the tree: " << avgAll << std::endl;

    int posCount = 0, posSum = 0;
    double avgPos = averagePositiveNodeValue(root, posCount, posSum);
    std::cout << "Average value of positive nodes in the tree: " << avgPos << std::endl;

    int negCount = 0, negSum = 0;
    double avgNeg = averageNegativeNodeValue(root, negCount, negSum);
    std::cout << "Average value of negative nodes in the tree: " << avgNeg << std::endl;

    int sumPos = 0, sumNeg = 0;
    double ratio = ratioPosToNeg(root, sumPos, sumNeg);
    std::cout << "Ratio of positive sum to negative sum: " << ratio << std::endl;

    return 0;
}