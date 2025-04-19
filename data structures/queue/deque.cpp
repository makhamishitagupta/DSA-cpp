#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class deque {
    Node* head;
    Node* tail;
public:
    deque() {
        head = tail = NULL;
    }

    void enqueue_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode; 
        }
    }

    void enqueue_back(int val) {
        Node* newNode = new Node(val);
        if (empty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode; 
        }
    }

    void dequeue_front() {
        if (empty()) {
            cout << "QUEUE IS EMPTY" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head == NULL) { 
            tail = NULL;
        }
        delete temp;
    }

    void dequeue_back() {
        if (empty()) {
            cout << "QUEUE IS EMPTY" << endl;
            return;
        }
        if (head == tail) { 
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    int front() {
        if (empty()) {
            cout << "QUEUE IS EMPTY" << endl;
            return -1; 
        }
        return head->data;
    }

    int rear() {
        if (empty()) {
            cout << "QUEUE IS EMPTY" << endl;
            return -1; 
        }
        return tail->data;
    }

    bool empty() {
        return head == NULL;
    }

    void print() {
        if (empty()) {
            cout << "QUEUE IS EMPTY" << endl;
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    deque dq;

    dq.enqueue_front(10);
    dq.enqueue_front(20);
    dq.enqueue_back(30);
    dq.enqueue_back(40);
    
    dq.print(); // Expected: 20 10 30 40

    cout << "Front: " << dq.front() << endl; // 20
    cout << "Rear: " << dq.rear() << endl; // 40

    dq.dequeue_front();
    dq.print(); // Expected: 10 30 40

    dq.dequeue_back();
    dq.print(); // Expected: 10 30

    cout << "Front: " << dq.front() << endl; // 10
    cout << "Rear: " << dq.rear() << endl; // 30

    return 0;
}
