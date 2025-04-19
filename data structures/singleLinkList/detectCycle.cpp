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
        Node *newNode = new Node(val); // dyanamic
        // Node newNode(val); // static
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head; //(*newNode).next=head
            head = newNode;
        }
    }

    bool detectCycle()
    {
        // slow fast pointer method
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }

    Node *detectCycleNode()
    {
        bool isCycle = false;
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                isCycle = true;
                break;
            }
        }

        if (isCycle)
        {
            slow = head;
            if (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            cout << slow;
        }
        else
        {
            return NULL;
        }
        slow = head;
        Node *prev = NULL;
        while (slow != fast)
        {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }

        prev->next = NULL; // remove cycle
        return slow;
    }
};

int main()
{
    List l1;
    l1.push_front(1);
    l1.push_front(2);
    l1.push_front(3);
    l1.push_front(4);
    cout << l1.detectCycle();
    l1.detectCycleNode();
    return 0;
}