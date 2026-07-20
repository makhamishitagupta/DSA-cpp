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

Node *buildTree(vector<int> &preorder)
{
    static int index = 0;
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

void allPaths(Node *root, string path, vector<string> &paths)
{
    if (root == nullptr)
        return;

    path += to_string(root->data) + " ";

    if (root->left == nullptr && root->right == nullptr) // Leaf node
    {
        paths.push_back(path);
        return;
    }

    allPaths(root->left, path, paths);
    allPaths(root->right, path, paths);
}

int main()
{
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1}; // -1 indicates null nodes
    Node *root = buildTree(preorder);
    vector<string> paths;
    allPaths(root, "", paths);
    cout << "All paths from root to leaf nodes:" << endl;
    for (const string &path : paths)
    {
        cout << path << endl;
    }
    delete root;   // Clean up memory (not necessary in this simple example, but good practice)
    paths.clear(); // Clear paths vector for potential reuse
    return 0;
}