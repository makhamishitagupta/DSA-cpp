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

Node *buildTree(vector<int> &preorder)
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

// Function for inorder traversal
// using Morris Traversal
vector<int> inOrder(Node *root)
{
    vector<int> res;
    Node *curr = root;

    while (curr != nullptr)
    {
        if (curr->left == nullptr)
        {

            // If no left child, visit this node
            // and go right
            res.push_back(curr->data);
            curr = curr->right;
        }
        else
        {

            // Find the inorder predecessor of curr
            Node *prev = curr->left;
            while (prev->right != nullptr &&
                   prev->right != curr)
            {
                prev = prev->right;
            }

            // Make curr the right child of its
            // inorder predecessor
            if (prev->right == nullptr)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {

                // Revert the changes made in
                // the tree structure
                prev->right = nullptr;
                res.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return res;
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preorder);

    cout << "Inorder Traversal using Morris Traversal: ";
    vector<int> result = inOrder(root);
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory (not necessary in this simple example, but good practice)
    delete root; // Assuming a proper destructor is defined for Node
    return 0;
}
