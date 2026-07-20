#include <iostream>
#include <vector>
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

vector<int> inorder(Node *root, vector<int> &result)
{
    if (!root)
        return result;

    inorder(root->left, result);
    result.push_back(root->data);
    inorder(root->right, result);

    return result;
}

int main()
{
    vector<int> arr = {5, 3, 8, 1, 4, 7, 9};
    Node *root = buildTree(arr);

    vector<int> result;
    result = inorder(root, result);

    // 3rd smallest element in the BST
    cout << result[3] << endl;

    return 0;
}