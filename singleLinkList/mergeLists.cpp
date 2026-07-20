#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
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

    void mergeLists(Node *head1, Node *head2)
    {
        if (!head1)
        {
            head = head2;
            return;
        }
        if (!head2)
        {
            head = head1;
            return;
        }

        Node *temp = head1;
        while (temp->next != NULL) // Stop at the last node of the first list
        {
            temp = temp->next;
        }
        temp->next = head2; // Link the last node of list1 to the head of list2
        head = head1;       // Update head to point to the merged list
    }

    void pushFront(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void printLL()
    {
        Node *temp = head; // address of head is stored in temp
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    Node *getHead()
    {
        return head;
    }
};

int main()
{
    List l1, l2;
    l1.pushFront(1);
    l1.pushFront(2);
    l1.pushFront(3);
    l1.pushFront(4);

    l2.pushFront(5);
    l2.pushFront(6);
    l2.pushFront(7);
    l2.pushFront(8);

    List m;
    m.mergeLists(l1.getHead(), l2.getHead());
    m.printLL();

    return 0;
}