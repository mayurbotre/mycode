#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    struct Node* next;
};

Node* newNode(int key) {
    Node* temp = new Node;
    temp->key = key;
    temp->next = NULL;
    return temp;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->key << " ";
        head = head->next;
    }
    cout << endl;
}

Node* detectAndRemoveLoop(Node* head) {
    if (head == NULL || head->next == NULL) return NULL;

    Node *slow = head, *fast = head;
    
    slow = slow->next;
    fast = fast->next->next;

    while (fast && fast->next) {
        if (slow == fast) break;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (slow != fast) return NULL;
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main() {
    Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);

    head->next->next->next->next->next = head->next->next;

    Node* res = detectAndRemoveLoop(head);
    if (res == NULL)
        cout << "Loop does not exist";
    else
        cout << "Loop starting node is " << res->key;
    return 0;
}