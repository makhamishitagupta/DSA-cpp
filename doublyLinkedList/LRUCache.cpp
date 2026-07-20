#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache
{
public:
    class Node
    {
    public:
        int key, val;
        Node *prev;
        Node *next;

        Node(int k, int v)
        {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    unordered_map<int, Node *> m;
    int limit;

    void addNode(Node *newNode)
    {
        Node *oldNext = head->next;

        head->next = newNode;
        oldNext->prev = newNode;

        newNode->next = oldNext;
        newNode->prev = head;
    }

    void delNode(Node *oldNode)
    {
        Node *oldPrev = oldNode->prev;
        Node *oldNext = oldNode->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    LRUCache(int capacity)
    {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (m.find(key) == m.end())
            return -1;

        Node *ansNode;
        int ans;
        ans = m[key]->val;
        ansNode = m[key];
        m.erase(key);
        delNode(ansNode);
        addNode(ansNode);
        m[key] = ansNode;

        return ans;
    }

    void put(int key, int val)
    {
        if (m.find(key) != m.end()) // checking if already exists
        {
            Node *oldNode = m[key]; // address is alvaible in map
            delNode(oldNode);
            m.erase(key);
        }

        if (m.size() == limit) // capacity of cache
        {
            // delete lru data
            m.erase(tail->prev->key);
            delNode(tail->prev);
        }

        Node *newNode = new Node(key, val);
        addNode(newNode);
        m[key] = newNode;
    }
};

int main()
{
    LRUCache ans(2); // Provide a capacity value, e.g., 2

    int num = 0;
    cout << "1. Put\n2. Get\n3. Exit" << endl;

    while (num != 3)
    {
        cout << "Enter the case: ";
        cin >> num;

        switch (num)
        {
        case 1:
        {
            int key, val;
            cout << "Enter key and value: ";
            cin >> key >> val;

            ans.put(key, val);
            break;
        }

        case 2:
        {
            int key;
            cout << "Enter the key to get value: ";
            cin >> key;

            cout << ans.get(key) << endl;
            break;
        }

        case 3:
        {
            cout << "Exiting the program...!!!";
            break;
        }

        default:
            cout << "Invalid choice";
        }
    }

    return 0;
}