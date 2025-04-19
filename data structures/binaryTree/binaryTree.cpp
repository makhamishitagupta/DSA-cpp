#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to build a binary tree from preorder traversal
Node* buildTree(vector<int>& preorder, int& index) {
    if (index >= preorder.size() || preorder[index] == -1) {
        index++;
        return nullptr;
    }

    Node* root = new Node(preorder[index++]);
    root->left = buildTree(preorder, index);
    root->right = buildTree(preorder, index);

    return root;
}

void treeToPreorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    treeToPreorder(root->left);
    treeToPreorder(root->right);
}

void treeToInorder(Node* root) {
    if (!root) return;
    treeToInorder(root->left);
    cout << root->data << " ";
    treeToInorder(root->right);
}

void treeToPostorder(Node* root) {
    if (!root) return;
    treeToPostorder(root->left);
    treeToPostorder(root->right);
    cout << root->data << " ";
}

void treeToLevelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, 4, -1, -1, 5, -1, -1};
    int index = 0;
    Node* root = buildTree(preorder, index);

    cout << "Root: " << root->data << endl;

    cout << "Preorder Traversal: "; 
    treeToPreorder(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    treeToInorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    treeToPostorder(root);
    cout << endl;

    return 0;
} 