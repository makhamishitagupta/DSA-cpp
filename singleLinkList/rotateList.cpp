#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Helper function to print the list
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a list from an array
ListNode *createList(const int arr[], int n)
{
    if (n == 0)
        return nullptr;
    ListNode *head = new ListNode(arr[0]);
    ListNode *curr = head;
    for (int i = 1; i < n; ++i)
    {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
            return head;

        // Step 1: Find length and last node
        ListNode *temp = head;
        int length = 1;
        while (temp->next)
        {
            temp = temp->next;
            length++;
        }

        // Step 2: Make list circular
        temp->next = head;

        // Step 3: Find new tail and new head
        k = k % length;
        int stepsToNewHead = length - k;
        ListNode *newTail = head;
        for (int i = 1; i < stepsToNewHead; i++)
        {
            newTail = newTail->next;
        }

        ListNode *newHead = newTail->next;
        newTail->next = nullptr; // Break the circle
        return newHead;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    ListNode *head = createList(arr, n);

    cout << "Original list: ";
    printList(head);

    Solution sol;
    int k = 2;
    ListNode *rotated = sol.rotateRight(head, k);

    cout << "Rotated list by " << k << ": ";
    printList(rotated);

    // Free memory
    while (rotated)
    {
        ListNode *temp = rotated;
        rotated = rotated->next;
        delete temp;
    }

    return 0;
}
