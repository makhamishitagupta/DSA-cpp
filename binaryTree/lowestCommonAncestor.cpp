#include <iostream>
#include <vector>
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
   
Node* findLCA(Node* root, int n1, int n2) {
    if (root == nullptr) {
        return nullptr;
    }
    
    if (root->data == n1 || root->data == n2) {
        return root;
    }
    
    Node* leftLCA = findLCA(root->left, n1, n2);
    Node* rightLCA = findLCA(root->right, n1, n2);
    
    if (leftLCA && rightLCA) {
        return root;
    }
    
    return (leftLCA != nullptr) ? leftLCA : rightLCA;
}

int main(){
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(preorder);
    cout << "Enter two nodes to find their LCA: ";
    int n1, n2;
    cin >> n1 >> n2;
    Node* lca = findLCA(root, n1, n2);
    if (lca) {
        cout << "LCA of " << n1 << " and " << n2 << " is: " << lca->data << endl;
    } else {
        cout << "LCA not found." << endl;
    }
    return 0;
}