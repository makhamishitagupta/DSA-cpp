#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList {
    Node* head;
    Node* tail;

public:
    DoublyList() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);

        if(head==NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);

        if(head==NULL){
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {
        Node* temp = head;
        head = head->next;

        if(head == NULL) {
            cout << "empty list" << endl;
            return;
        }

        if(head != NULL) {
            head->prev = NULL;
        }

        temp->next = NULL;
        delete temp;
    }

    void pop_back(){
        Node* temp = tail;
        tail = tail->prev;

        if(head == NULL) {
            cout << "empty list" << endl;
            return;
        }

        if(tail != NULL) {
            tail->next = NULL;
        } 

        temp->prev = NULL;
        delete temp;
    }

    void printLL() {
        Node* temp = head;
        while(temp!=NULL) {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

};

int main() {
    DoublyList dll;

    dll.push_front(4);
    dll.push_front(3);
    dll.push_front(2);
    dll.push_front(1);

    dll.push_back(5);
    dll.push_back(6);
    dll.push_back(7);

    dll.printLL();

    dll.pop_back();
    dll.pop_front();
    dll.printLL();

    return 0;
}