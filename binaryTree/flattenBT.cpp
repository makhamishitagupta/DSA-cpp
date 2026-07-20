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

    // Static index for preorder building
    static Node *buildTree(vector<int> &preorder)
    {
        static int index = 0;
        if (index >= preorder.size() || preorder[index] == -1)
        {
            index++;
            return nullptr;
        }

        Node *root = new Node(preorder[index++]);
        root->left = buildTree(preorder);
        root->right = buildTree(preorder);
        return root;
    }

    // Flatten function helper (reverse preorder)
    void flatten(Node *root)
    {
        static Node *nextRight = nullptr;

        if (!root)
            return;

        flatten(root->right);
        flatten(root->left);

        root->right = nextRight;
        root->left = nullptr;
        nextRight = root;
    }

    // Print flattened tree as linked list
    void printFlattened(Node *root)
    {
        while (root)
        {
            cout << root->data << " ";
            root = root->right;
        }
        cout << endl;
    }

    // Optional: clean up memory
    void deleteTree(Node *root)
    {
        if (!root)
            return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};

int main()
{
    vector<int> preorder = {1, 2, 3, -1, -1, 4, -1, -1, 5, -1, 6, -1, -1};

    Node *root = Node::buildTree(preorder);

    Node handler(0); // dummy object to call non-static member functions
    handler.flatten(root);

    cout << "Flattened tree: ";
    handler.printFlattened(root);

    handler.deleteTree(root); // Free memory
    return 0;
}
