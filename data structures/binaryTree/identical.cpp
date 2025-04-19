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
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }

        if (root1 == nullptr || root2 == nullptr) {
            return false;
        }

        // if(root1 == nullptr || root2 == nullptr) {
        //    return root1 == root2;
        // }

        return (root1->data == root2->data) &&
               areIdentical(root1->left, root2->left) &&
               areIdentical(root1->right, root2->right);
    }
};

int main() {
    BinaryTree tree;

    // Tree 1
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    // Tree 2
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    if (tree.areIdentical(root1, root2)) {
        cout << "The trees are identical." << endl;
    } else {
        cout << "The trees are not identical." << endl;
    }

    return 0;
}
