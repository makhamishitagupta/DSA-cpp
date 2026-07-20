#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node *insert(Node *root, int value)
{
    if (!root)
        return new Node(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

Node *buildTree(vector<int> arr)
{
    Node *root = nullptr;
    for (int value : arr)
    {
        root = insert(root, value);
    }
    return root;
}

bool isBst(Node *root, Node *min, Node *max)
{
    if (root == NULL)
        return true; // An empty tree is a valid BST

    if (min != NULL && root->data <= min->data)
        return false; // Check if current node is greater than min
    if (max != NULL && root->data >= max->data)
        return false; // Check if current node is less than max

    return isBst(root->left, min, root) && // Check left subtree with updated max
           isBst(root->right, root, max);  // Check right subtree with updated min
}

bool isValidBSTUtil(Node *node, long minVal, long maxVal)
{
    if (!node)
        return true;
    if (node->data <= minVal || node->data >= maxVal) // checking the value is b/w min and max
        return false;
    return isValidBSTUtil(node->left, minVal, node->data) &&
           isValidBSTUtil(node->right, node->data, maxVal);
}

int main()
{
    vector<int> arr = {10, 5, 15, 3, 7, 18};
    Node *root = buildTree(arr);

    if (isValidBSTUtil(root, LONG_MIN, LONG_MAX))
        cout << "The tree is a valid BST." << endl;
    else
        cout << "The tree is not a valid BST." << endl;
}