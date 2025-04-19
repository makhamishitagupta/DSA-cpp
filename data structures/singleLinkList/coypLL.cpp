#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;
    Node(int val)
    {
        data = val;
        next = NULL;
        random = NULL;
    }
};

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    Node *copyLists(Node *head)
    {
        if (head == NULL)
            return NULL;
        unordered_map<Node *, Node *> m;

        Node *newHead = new Node(head->data);
        Node *oldTemp = head->next;
        Node *newTemp = newHead;

        m[head] = newHead;

        while (oldTemp != NULL)
        {
            Node *copyNode = new Node(oldTemp->data);
            m[oldTemp] = copyNode;
            newTemp->next = copyNode;

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        oldTemp = head;
        newTemp = newHead;
        while (oldTemp != NULL)
        {
            newTemp->random = m[oldTemp->random];

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }

    void printList(Node *head)
    {
        Node *temp = head;
        while (temp)
        {
            cout << "Data: " << temp->data;
            if (temp->random)
                cout << ", Random: " << temp->random->data << endl;
            else
                cout << ", Random: NULL" << endl;
            temp = temp->next;
        }
    }

    Node *getHead()
    {
        return head;
    }

    Node *setHead(Node *head, Node *newHead)
    {
        head = newHead;
    }
};

int main()
{
    List list;

    // Create the original list with random pointers
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    head->random = head->next->next;       // 1's random points to 3
    head->next->random = head;             // 2's random points to 1
    head->next->next->random = head->next; // 3's random points to 2

    cout << "Original List: " << endl;
    list.printList(head);

    cout << "Copied List: " << endl;
    list.setHead(head, list.copyLists(head));
    list.printList(head);

    return 0;
}