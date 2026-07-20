#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node *insert(Node *root, int val)
{
    if (!root)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// burte force approach to build BST from preorder traversal
// Time complexity: O(n^2) in the worst case, where n is the number of nodes.
// Space complexity: O(n) for the recursion stack.
Node *buildTree(vector<int> preorder)
{
    Node *root = nullptr;
    for (int i = 0; i < preorder.size(); ++i)
    {
        root = insert(root, preorder[i]);
    }
    return root;
}

// Optimized approach to build BST from preorder traversal
// Time complexity: O(n), where n is the number of nodes.
// Space complexity: O(h), where h is the height of the tree (O(log n) for balanced trees).
Node *buildTreeUtil(vector<int> &preorder, int &index, int key, int min, int max)
{
    if (index >= preorder.size())
        return nullptr;

    int value = preorder[index];
    if (value < min || value > max)
        return nullptr;

    Node *root = new Node(value);
    index++;

    root->left = buildTreeUtil(preorder, index, key, min, value);
    root->right = buildTreeUtil(preorder, index, key, value, max);

    return root;
}

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    vector<int> preorder = {6, 3, 1, 4, 8, 9};
    Node *root = buildTree(preorder);
    cout << "Inorder traversal of the constructed BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
