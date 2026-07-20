#include<iostream>
#include<vector>
using namespace std;

// This code defines a binary tree and prints the nodes at the kth level of the tree.

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* buildTree(vector<int>& preorder) {
    static int index = 0;
    if (index >= preorder.size() || preorder[index] == -1) {
        index++;
        return nullptr;
    }

    Node* root = new Node(preorder[index++]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

void kthLevel(Node* root, int k) {
    if (root == nullptr) return;

    if (k == 1) {
        cout << root->data << " ";
        return;
    }

    kthLevel(root->left, k - 1);
    kthLevel(root->right, k - 1);
}

int main() {
    vector<int> preorder = {1, 2, 7, -1, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);

    kthLevel(root, 3);

    return 0;
}