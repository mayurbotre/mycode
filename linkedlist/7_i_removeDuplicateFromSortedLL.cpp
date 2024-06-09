#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
      Node(int x) {
        data = x;
          next = NULL;
    }
};

void removeDuplicates(Node* head) {
    Node* to_free;

    if (head == NULL) return;

    if (head->next != NULL) {
        if (head->data == head->next->data) {
            to_free = head->next;
            head->next = head->next->next;
            free(to_free);
            removeDuplicates(head);
        }
        else {
            removeDuplicates(head->next);
        }
    }
}

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void printList(Node* node)
{
    while (node != NULL) {
        cout << " " << node->data;
        node = node->next;
    }
}

int main() {

    Node* head = NULL;

    push(&head, 20);
    push(&head, 13);
    push(&head, 13);
    push(&head, 11);
    push(&head, 11);
    push(&head, 11);

    cout << "Linked list before duplicate removal ";
    printList(head);

    removeDuplicates(head);

    cout << "\nLinked list after duplicate removal ";
    printList(head);

    return 0;
}