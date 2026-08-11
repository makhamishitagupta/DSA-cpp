#include <iostream>
#include <vector>
#include <map>
#include <queue>
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

static int index = 0;
Node *buildTree(vector<int> &preorder)
{
    if (index >= preorder.size() || preorder[index] == -1)
    {
        index++;
        return nullptr;
    }

    Node *root = new Node(preorder[index++]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

void bottomView(Node *root)
{
    queue<pair<Node *, int>> q;
    map<int, int> bottomViewMap; // To store the first node at each horizontal distance
    q.push({root, 0});           // Start with the root at horizontal distance 0

    while (!q.empty())
    {
        auto front = q.front();
        q.pop();
        Node *node = front.first;
        int nodeHD = front.second; // Horizontal distance

        // If this is the first time we are visiting this horizontal distance, add it to the map
        bottomViewMap[nodeHD] = node->data;

        // Push left and right children with updated horizontal distances
        if (node->left)
        {
            q.push({node->left, nodeHD - 1});
        }
        if (node->right)
        {
            q.push({node->right, nodeHD + 1});
        }
    }

    // Print the top view nodes in sorted order of their horizontal distances
    for (auto it : bottomViewMap)
    {
        cout << it.second << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preorder);

    bottomView(root);
}