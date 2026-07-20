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

int search(vector<int> &inoder, int key, int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        if (inoder[i] == key)
            return i;
    }

    return -1;
}

Node *buildTree(vector<int> &preorder, vector<int> &inorder, int &preIndex, int l, int r)
{
    if (l > r)
        return NULL;

    Node *root = new Node(preorder[preIndex]);
    preIndex++;

    int inIdx = search(inorder, root->data, l, r);
    root->left = buildTree(preorder, inorder, preIndex, l, inIdx - 1);
    root->right = buildTree(preorder, inorder, preIndex, inIdx + 1, r);

    return root;
}

int main()
{
    vector<int> preOrder = {1, 2, 4, 5, 3};
    vector<int> inOrder = {4, 2, 5, 1, 3};

    int preIndex = 0;
    Node *root = buildTree(preOrder, inOrder, preIndex, 0, inOrder.size() - 1);
    cout << "Tree built successfully." << endl;

    return 0;
}