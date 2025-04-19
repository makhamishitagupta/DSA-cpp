#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class queue_LL{
    Node* head;
    Node* tail;
public:

    queue_LL() {
        head = tail = NULL;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if(empty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode = tail;
        }
    }

    void dequeue() {
        Node *temp = head;
        if (empty()){
            cout << "QUEUE IS EMPTY" << endl;
            return;
        } 
        
        head = head->next;
        delete temp;
    }

    int front() {
        return head->data;
    }

    bool empty() {
        if(head == NULL) {
            return true;
        }

        return false;
    }

};

int main(){
    queue_LL q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q.front() << endl;

    return 0;
}