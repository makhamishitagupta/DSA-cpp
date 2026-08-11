#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to build a binary tree from preorder traversal
Node *buildTree(vector<int> &preorder, int &index)
{
    if (index >= preorder.size() || preorder[index] == -1)
    {
        index++;
        return nullptr;
    }

    Node *root = new Node(preorder[index++]);
    root->left = buildTree(preorder, index);
    root->right = buildTree(preorder, index);

    return root;
}

void helper(Node *root, vector<int> &path, vector<vector<int>> &ans)
{
    if (!root)
        return;

    path.push_back(root->data);

    if (root->left == nullptr && root->right == nullptr)
    {
        ans.push_back(path);
    }
    else
    {
        helper(root->left, path, ans);
        helper(root->right, path, ans);
    }

    path.pop_back();
}

void allRootToLeaf(Node *root)
{
    vector<vector<int>> ans;
    vector<int> path;
    helper(root, path, ans);

    for (auto i : ans)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, 4, -1, -1, 5, -1, -1};
    int index = 0;
    Node *root = buildTree(preorder, index);

    allRootToLeaf(root);

    return 0;
}