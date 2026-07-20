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

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool search(Node *root, int value)
{
    if (!root)
        return false;
    if (root->data == value)
        return true;
    else if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

Node *deleteNode(Node *root, int value)
{
    if (!root)
        return nullptr;

    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        // Node with one child or no child
        if (!root->left)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node *temp = root->right;
        while (temp && temp->left)
        {
            temp = temp->left;
        }
        root->data = temp->data;                           // Copy the inorder successor's content to this node
        root->right = deleteNode(root->right, temp->data); // Delete the inorder successor
    }
    return root;
}

int main()
{
    vector<int> arr = {5, 3, 8, 1, 4, 7, 9};
    Node *root = buildTree(arr);
    cout << "Inorder traversal of the BST: ";
    inorder(root);

    cout << endl;
    int searchValue = 4;
    if (search(root, searchValue))
        cout << "Value " << searchValue << " found in the BST." << endl;
    else
        cout << "Value " << searchValue << " not found in the BST." << endl;

    return 0;
}