#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
      
    Node(int x) {
        data = x;
          next = NULL;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void detectAndRemoveLoop(Node* head) {

    if (head == NULL || head->next == NULL) return;

    Node *slow = head, *fast = head;

    slow = slow->next;
    fast = fast->next->next;

    while (fast && fast->next) {
        if (slow == fast) break;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (slow == fast) {

        slow = head;

        if (slow == fast)
            while (fast->next != slow) fast = fast->next;
        else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        fast->next = NULL;

    }
}

int main() {

    Node* head = new Node(50);

    head->next = new Node(20);
    head->next->next = new Node(15);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(10);

    head->next->next->next->next->next = head;

    detectAndRemoveLoop(head);

    printf("Linked List after removing loop \n");
    printList(head);

    return 0;
}