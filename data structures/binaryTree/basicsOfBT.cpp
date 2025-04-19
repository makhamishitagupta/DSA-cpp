#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* buildTree(vector<int>& preorder, int& index) {
    index++; 
    if (index >= preorder.size() || preorder[index] == -1) {
        index++;
        return nullptr;
    }

    Node* root = new Node(preorder[index++]);
    root->left = buildTree(preorder, index);
    root->right = buildTree(preorder, index);
    return root;
}

int height(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    // int left = 0, right = 0;
    // left = height(root->left);
    // right = height(root->right);

    // return 1 + max(left, right); // 1 for the current node + max of left and right subtree heights
    return 1 + max(height(root->left), height(root->right));
}

int count(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    // int left = 0, right = 0;
    // left = count(root->left);
    // right = count(root->right);

    // return 1 + left + right; // 1 for the current node + left subtree + right subtree
    return 1 + count(root->left) + count(root->right); 
}

int sum(Node* root) {
    if(!root) {
        return 0;
    }

    // int left = 0, right = 0;
    // left = sum(root->left);
    // right = sum(root->right);

    // return root->data + left + right; // 1 for the current node + left subtree + right subtree
    return root->data + sum(root->left) + sum(root->right);
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int index = -1;
    Node* root = buildTree(preorder, index);

    cout << "Height of the tree: " << height(root) << endl;
    cout << "Count of nodes in the tree: " << count(root) << endl;

    return 0;
}