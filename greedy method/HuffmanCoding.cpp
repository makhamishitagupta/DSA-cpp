/*
🔷 Problem 3: Huffman Coding
Given characters and their frequencies, construct the optimal binary prefix code
(minimum average code length) using a greedy tree-building algorithm.
*/

#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(NULL), right(NULL) {}
};

class Compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

class HuffmanCoding
{
public:
    void printCodes(Node *root, string str)
    {
        if (!root)
            return;
        if (root->ch != '$')
            cout << root->ch << ": " << str << "\n";
        printCodes(root->left, str + "0");
        printCodes(root->right, str + "1");
    }

    void buildHuffman(char data[], int freq[], int n)
    {
        priority_queue<Node *, vector<Node *>, Compare> minHeap;
        for (int i = 0; i < n; i++)
            minHeap.push(new Node(data[i], freq[i]));

        while (minHeap.size() > 1)
        {
            Node *left = minHeap.top();
            minHeap.pop();
            Node *right = minHeap.top();
            minHeap.pop();
            Node *merged = new Node('$', left->freq + right->freq);
            merged->left = left;
            merged->right = right;
            minHeap.push(merged);
        }
        printCodes(minHeap.top(), "");
    }
};

int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    HuffmanCoding obj;
    obj.buildHuffman(arr, freq, 6);
    return 0;
}
