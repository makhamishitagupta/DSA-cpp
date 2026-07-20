#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class list{
    Node* head;
    Node* tail;
public:
    list(){
        head = NULL;
        tail = NULL;
    }

    void pushFront(int val){
        Node *newNode = new Node(val); // dynamic allocation of new node
        if (head == NULL){
            head = tail = newNode; // If the list is empty, set both head and tail to the new node
            return;
        }
        else{
            newNode->next = head; // Insert new node at the front
            head = newNode;
        }
    }

    Node* reverseKGroups(Node* head, int k){
        Node* temp = head;
        int count = 0;

        // Check if there are k nodes available to reverse
        while(count < k) {
            if(temp == NULL) return head; // Less than k nodes remaining, no reversal
            temp = temp -> next;
            count++;
        }

        // Recursively reverse the next k-group
        Node* prevNode = reverseKGroups(temp, k);

        // Reverse the current group of k nodes
        temp = head;
        count = 0;
        Node* nextNode = NULL;
        while(count < k) {
            nextNode = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = nextNode;
            count++;
        }

        // Return the new head after reversal of this group
        return prevNode;
    }

    void reverseK(int k){
        head = reverseKGroups(head, k);
    }

    void printLL(){
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main(){
    list l1;
    l1.pushFront(1);
    l1.pushFront(2);
    l1.pushFront(3);
    l1.pushFront(4);
    l1.pushFront(5);
    l1.pushFront(6);
    l1.pushFront(7);
    l1.pushFront(8);
    l1.pushFront(9);
    
    cout << "Original linked list: ";
    l1.printLL();
    
    int k = 3;
    l1.reverseK(k); // Reverses the linked list in groups of k
    cout << "Linked list after reversing in groups of " << k << ": ";
    l1.printLL();

    return 0;
}
