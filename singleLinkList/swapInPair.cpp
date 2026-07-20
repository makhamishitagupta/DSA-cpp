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
public:
    Node *head;
    Node *tail;
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

    Node *getHead()
    {
        return head;
    }

    // answer
    Node* swapPairs(Node *head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        Node* first = head;
        Node* sec = head->next;
        Node* prev = NULL;

        while ((first != NULL && sec != NULL)) {
            Node* third = sec->next;

            sec->next = first;
            first->next = third;

            if(prev != NULL) prev->next = sec;
            else head = sec;

            // update
            prev = first;
            first = third;
            if(third != NULL) sec = third->next;
            else sec = NULL;
        }

        return head;  
    }
};

int main() {
    List l1;
    l1.pushFront(5);
    l1.pushFront(4);
    l1.pushFront(3);
    l1.pushFront(2);
    l1.pushFront(1);

    // Swap pairs in l1
    l1.head = l1.swapPairs(l1.getHead());  // Directly update the head of l1

    l1.printLL();  // Print the modified list


    return 0;
}