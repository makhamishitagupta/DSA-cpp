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

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    Node *mergeSortedLists(Node *head1, Node *head2)
    {
        if (head1 == NULL || head2 == NULL)
        {
            return head1 == NULL ? head2 : head1;
        }

        if (head1->data <= head2->data)
        {
            head1->next = mergeSortedLists(head1->next, head2);
            return head1;
        }
        else
        {
            head2->next = mergeSortedLists(head1, head2->next);
            return head2;
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

    void setHead(Node *newHead)
    {
        head = newHead;
    }
};

int main()
{
    List l1, l2;
    l1.push_front(5);
    l1.push_front(3);
    l1.push_front(1);

    l2.push_front(6);
    l2.push_front(4);
    l2.push_front(2);

    List merge;
    merge.setHead(merge.mergeSortedLists(l1.getHead(), l2.getHead()));
    merge.printLL();

    return 0;
}