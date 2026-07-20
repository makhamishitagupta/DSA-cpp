#include <iostream>
#include <vector>
#include <algorithm>
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

void minDistance(Node *root, Node *&prev, int &ans)
{
    // Process:
    // 1. Traverse the BST in-order to get sorted order of elements.
    // 2. Keep track of the previous node and calculate the distance with the current node.
    // 3. Update the minimum distance found so far.

    // why we using sorted order?
    // Because in a BST, in-order traversal gives us the elements in sorted order.
    // The minimum distance between any two nodes will be between adjacent nodes in this sorted order.

    if (!root)
        return;

    minDistance(root->left, prev, ans);
    if (prev)
    {
        ans = min(ans, abs(root->data - prev->data));
    }
    prev = root;
    minDistance(root->right, prev, ans);
}
int main()
{
    vector<int> arr = {10, 5, 15, 3, 7, 13, 18};
    Node *root = buildTree(arr);

    Node *prev = nullptr;
    int ans = INT_MAX;
    minDistance(root, prev, ans);
    cout << "Minimum distance: " << ans << endl;

    return 0;
}