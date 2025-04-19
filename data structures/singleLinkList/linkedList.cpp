#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;   // points to address of next node //next is pointer of type node
    Node(int val) // constructer
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
    List() // constructer
    {
        head = tail = NULL;
    }

    void pushFront(int val)
    {
        Node *newNode = new Node(val); // dyanamic  //created a node
        // Node newNode(val); // static
        if (head == NULL)
        {
            head = tail = newNode; // similar to *head = &newNode but we are not using &
            return;
        }
        else
        {
            newNode->next = head; //(*newNode).next=head //we are accessing the next pointer in the newNode
            head = newNode;
        }
    }

    void pushBack(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front()
    {
        // we are separating the 1st node from the list by moving the header one step a head and changing its next to NULL
        Node *temp = head;
        head = temp->next;
        temp->next = NULL;
    }

    void pop_back()
    {
        Node *temp = head;
        if (head == NULL)
        {
            return;
        }
        while (temp->next != tail)
        {
            // if(temp->next->next==NULL)
            temp = temp->next; // to store the address of tail ka previous element
        }
        temp->next = NULL;
        delete tail; // data in the tail will be deleted not the variable of the tail
        tail = temp;
    }

    void insert(int val, int pos)
    {
        Node *newNode = new Node(val);
        Node *temp = head;
        if (pos < 0)
        {
            return;
        }
        if (pos == 0)
        {
            pushBack(val);
        }
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "invalid position i.e it excides the limit" << endl;
                return;
            }
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode; // &newNode
    }

    int search(int key)
    {
        Node *temp = head;
        int i = 0, found = -1;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                found = i;
                break;
            }

            temp = temp->next;
            i++;
        }
        return found;
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
    void printNode(Node *node)
    {
        if (node)
        {
            cout << "Node Data: " << node->data << endl;
        }
        else
        {
            cout << "Node is null." << endl;
        }
    }
};

int main()
{
    List l1;
    l1.pushFront(1);
    l1.pushFront(2);
    l1.pushFront(3);
    l1.pushBack(4);
    l1.printLL();
    l1.pop_front();
    l1.pop_back();
    l1.insert(7, 2);
    l1.printLL();
    cout << l1.search(7);

    return 0;
}