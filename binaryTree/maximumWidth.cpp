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

int maximumWidth(Node *root)
{
    if (!root)
        return 0;

    queue<pair<Node *, int>> q; // Node and its index in the level
    q.push({root, 0});
    int maxWidth = 0;

    while (!q.empty())
    {
        int size = q.size();
        int firstIndex = q.front().second;
        int lastIndex = q.back().second;

        maxWidth = max(maxWidth, lastIndex - firstIndex + 1);

        for (int i = 0; i < size; i++)
        {
            auto current = q.front();
            q.pop();
            Node *node = current.first;
            int index = current.second;

            if (node->left)
                q.push({node->left, 2 * index + 1}); // Left child index
            if (node->right)
                q.push({node->right, 2 * index + 2}); // Right child index
        }
    }

    return maxWidth;
}

int main()
{
    vector<int> preorder = {1, 3, 5, -1, -1, 3, -1, -1, 2, -1, 9, -1, -1};
    int index = 0;
    Node *root = buildTree(preorder, index);

    int maxWidth = maximumWidth(root);
    cout << "Maximum width of the binary tree: " << maxWidth << endl;

    delete root;
    return 0;
}