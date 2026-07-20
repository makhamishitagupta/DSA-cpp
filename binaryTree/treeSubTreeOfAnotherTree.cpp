#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() : root(nullptr) {}

    bool areIdentical(Node* root1, Node* root2) {

        if(root1 == nullptr || root2 == nullptr) {
            return root1 == root2;
        }

        return (root1->data == root2->data) &&
               areIdentical(root1->left, root2->left) &&
               areIdentical(root1->right, root2->right);
    }

    bool isSubtree(Node* root, Node* subRoot) {
        if (subRoot == nullptr) return true; // An empty tree is a subtree of any tree
        if (root == nullptr) return false; // Non-empty tree cannot be a subtree of an empty tree

        if ((root->data==subRoot->data) && (areIdentical(root, subRoot))) {
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

int main() {
    BinaryTree tree;

    // Tree 1
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->right->left = new Node(4);
    root1->right->right = new Node(5);

    // Tree 2
    Node* root2 = new Node(3);
    root2->left = new Node(4);
    root2->right = new Node(5);

    if (tree.isSubtree(root1, root2)) {
        cout << "TRUE" << endl;
    } else {
        cout << "FALSE" << endl;
    }

    return 0;
}
