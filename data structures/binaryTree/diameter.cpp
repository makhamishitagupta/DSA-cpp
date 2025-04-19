#include <iostream>
#include <algorithm> // For std::max
#include <vector>
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
    
        int height(Node* node) {
            if(node == nullptr) {
                return 0;
            }
            return max(height(node->left), height(node->right)) + 1;
        }

        int diameter(Node* root) {
            // O(n^2) time complexity
            // O(h) space complexity

            if(root == nullptr) {
                return 0;
            }

            int leftDiameter = diameter(root->left);
            int rightDiameter = diameter(root->right);
            int currentDiameter = height(root->left) + height(root->right) + 1;

            return max(currentDiameter, max(leftDiameter, rightDiameter));
        }

        int heightOptimized(Node* root, int &diameter) {
            if (root == nullptr) return 0;
        
            int lh = heightOptimized(root->left, diameter);
            int rh = heightOptimized(root->right, diameter);
        
            // update diameter at this node
            diameter = max(diameter, lh + rh + 1);
        
            return max(lh, rh) + 1;
        }
        
        int diameterOptimized(Node* root) {
            int diameter = 0;
            heightOptimized(root, diameter);
            return diameter;
        }
        
    };

int main() {
    BinaryTree tree;
    tree.root = new Node(1);
    tree.root->left = new Node(2);
    tree.root->right = new Node(3);
    tree.root->left->left = new Node(4);
    tree.root->left->right = new Node(5);
    tree.root->right->left = new Node(6);
    tree.root->right->right = new Node(7);
    tree.root->left->left->left = new Node(8);
    tree.root->left->left->right = new Node(9);
    tree.root->left->right->left = new Node(10);
    tree.root->left->right->right = new Node(11);
    tree.root->right->left->left = new Node(12);
    tree.root->right->left->right = new Node(13);
    tree.root->right->right->left = new Node(14);
    tree.root->right->right->right = new Node(15);
    
    cout << "Diameter of the binary tree is: " << tree.diameter(tree.root) << endl;
    cout << "Optimized diameter of the binary tree is: " << tree.diameterOptimized(tree.root) << endl;
    cout << "Height of the binary tree is: " << tree.height(tree.root) << endl;
    // Clean up memory (optional, but good practice)
    delete tree.root->left->left->left;
    delete tree.root->left->left->right;
    delete tree.root->left->right->left;
    delete tree.root->left->right->right;
    delete tree.root->right->left->left;
    delete tree.root->right->left->right;
    delete tree.root->right->right->left;
    delete tree.root->right->right->right;
    delete tree.root->left->left;
    delete tree.root->left->right;
    delete tree.root->right->left;
    delete tree.root->right->right;
    delete tree.root->left;
    delete tree.root->right;
    delete tree.root;
    tree.root = nullptr; // Set root to nullptr after deletion


    return 0;
}