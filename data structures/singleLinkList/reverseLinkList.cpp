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
    // Node(){
    //     data = 0;
    //     next = NULL;
    // }
    // Node(int val, Node* n){
    //     data = val;
    //     next = n;
    // }
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
        Node *newNode = new Node(val); // dyanamic  //created a node
        // Node newNode(val); // static
        if (head == NULL){
            head = tail = newNode; // similar to *head = &newNode but we are not using &
            return;
        }
        else{
            newNode->next = head; //(*newNode).next=head //we are accessing the next pointer in the newNode
            head = newNode;
        }
    }

    void reverse(){
        Node* current;
        Node* previous;
        Node* after; //basically next to current
        previous = after = NULL;
        current = head;
        while(current != NULL){
            after = current->next;       // 1st store the next node in after
            current->next = previous;   // 2nd reverse the current node's next pointer to point to previous node
            // 3rd move the previous and current pointer one step forward
            previous = current;
            current = after;    
        }
        head = previous;
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
};

int main(){
    list l1;
    l1.pushFront(1);
    l1.pushFront(2);
    l1.pushFront(3);
    l1.pushFront(4);
    l1.pushFront(5);
    l1.printLL();
    l1.reverse();
    cout<<"reverse linked list is ";  
    l1.printLL();

    return 0;
}