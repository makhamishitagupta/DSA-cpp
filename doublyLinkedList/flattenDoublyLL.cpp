#include <bits/stdc++.h>
using namespace std;

// Node structure for a doubly linked list with child pointers
class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node* child;

    Node(int value) : val(value), next(nullptr), prev(nullptr), child(nullptr) {}

    // int val;
    // Node* next;
    // Node* prev;
    // Node* child;

    // // Constructor using assignments instead
    // Node(int value) {
    //     val = value;
    //     next = nullptr;
    //     prev = nullptr;
    //     child = nullptr;
    // }
};

// Helper function to flatten the list and return the tail
Node* flattenRecursive(Node* head) {
    if (head == NULL) return head;   // base case

    Node* curr = head;
    
    while (curr) {
        if(curr->child != NULL) {
            // flatten the child nodes
            Node* next = curr->next;
            curr->next = flattenRecursive(curr->child);

            curr->next->prev = curr;
            curr->child = NULL;

            // find the tail 
            while(curr->next != NULL) {
                curr = curr->next;
            }

            // attach the tail with next ptr
            if(next != NULL) {
                curr->next = next;
                next->prev = curr;
            }
        }

        curr = curr->next;
    }

    return head;
}

// Function to flatten the list and return the new head
Node* flatten(Node* head) {
    flattenRecursive(head);
    return head;
}

// Utility function to print the flattened list
void printList(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Sample usage
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    head->child = new Node(4);
    head->child->next = new Node(5);
    head->child->next->prev = head->child;
    
    head->next->child = new Node(6);
    head->next->child->next = new Node(7);
    head->next->child->next->prev = head->next->child;

    Node* flattenedHead = flatten(head);
    printList(flattenedHead);

    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// struct Node {
//     int val;
//     Node* next;
//     Node* prev;
//     Node* child;
    
//     Node(int value) : val(value), next(nullptr), prev(nullptr), child(nullptr) {}
// };

// // Function to flatten the multilevel doubly linked list
// Node* flatten(Node* head) {
//     if (!head) return nullptr;

//     stack<Node*> stk;
//     Node* curr = head;

//     while (curr) {
//         if (curr->child) {
//             if (curr->next) stk.push(curr->next); // Push next node to process later
//             curr->next = curr->child;
//             curr->next->prev = curr;
//             curr->child = nullptr; // Remove child reference
//         } 
//         if (!curr->next && !stk.empty()) {
//             curr->next = stk.top();
//             stk.top()->prev = curr;
//             stk.pop();
//         }
//         curr = curr->next;
//     }
    
//     return head;
// }

// // Utility function to print the flattened list
// void printList(Node* head) {
//     while (head) {
//         cout << head->val << " ";
//         head = head->next;
//     }
//     cout << endl;
// }

// // Sample usage
// int main() {
//     Node* head = new Node(1);
//     head->next = new Node(2);
//     head->next->prev = head;
//     head->next->next = new Node(3);
//     head->next->next->prev = head->next;

//     head->child = new Node(4);
//     head->child->next = new Node(5);
//     head->child->next->prev = head->child;
    
//     head->next->child = new Node(6);
//     head->next->child->next = new Node(7);
//     head->next->child->next->prev = head->next->child;

//     Node* flattenedHead = flatten(head);
//     printList(flattenedHead);

//     return 0;
// }
