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

    int middleoftheLL(){
        //timecomplexity O(n), space complexity O(1)
        Node* temp = head;
        int n=0;
        while(temp!=NULL){
            n++;
            temp = temp->next;
        }
        temp=head;
        for(int i=0; i<n/2; i++){
            temp = temp->next;
        }
        int middle;
        middle = temp->data;
        return middle;
    }

    int middleOptimal(){
        //SLOW FAST POINTER
        //IMPORTANT METHOD -> single loop
        Node* slow = head;
        Node* fast = head;

        // Fast pointer moves two steps, slow moves one step
        while (fast != NULL && fast->next != NULL) {  //one for even nodes and other for odd node
            slow = slow->next;
            fast = fast->next->next;
        }

    return slow->data; // Slow pointer points to the middle
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
    //l1.pushFront(6);
    l1.printLL();
    cout<<l1.middleoftheLL();

    return 0;
}