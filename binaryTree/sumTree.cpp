#include<iostream>
#include<vector>
using namespace std;

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

void preorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
        
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int sumTree(Node* root) {   // O(n) time complexity, O(h) space complexity
    // where n is the number of nodes in the tree and h is the height of the tree.
    if (root == nullptr) {
        return 0;
    }
    
    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);
    
    root->data += leftSum + rightSum;
    
    return root->data;
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);
    
    cout << "Preorder Traversal before sumTree: ";
    preorderTraversal(root);
    cout << endl;

    sumTree(root);

    cout << "Preorder Traversal after sumTree: ";
    preorderTraversal(root);
    cout << endl;
    
    return 0;
}