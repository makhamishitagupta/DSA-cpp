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

Node *sortedArrayToBST(vector<int> &nums, int left, int right)
{
    if (left > right)
        return nullptr;

    int mid = left + (right - left) / 2;
    Node *root = new Node(nums[mid]);
    root->left = sortedArrayToBST(nums, left, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, right);

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
    vector<int> sortedArray = {-10, -3, 0, 5, 9};
    Node *root = sortedArrayToBST(sortedArray, 0, sortedArray.size() - 1);

    // Example usage: Inorder traversal to verify the BST
    inorder(root);
    cout << endl;

    return 0;
}