#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
      Node(int x) {
        data = x;
          next = NULL;
    }
};

Node* newNode(int data) {
    Node* new_node = new Node(data);
    new_node->next = NULL;
    return new_node;
}

void push(Node** head_ref, int new_data) {

    Node* new_node = newNode(new_data);

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

struct Node* reverseList(struct Node* list) {
    Node *prev = NULL, *cur = list, *next = NULL;
    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

Node* addTwoLists(Node* first, Node* second) {
    first = reverseList(first);
    second = reverseList(second);

    int carry = 0;
    Node *head = NULL, *prev = NULL;
    Node* sum = NULL;

    while (first != NULL or second != NULL or carry == 1) {
        int newVal = carry;
        if (first)
            newVal += first->data;
        if (second)
            newVal += second->data;

        carry = newVal / 10;
        newVal = newVal % 10;
        Node* newNode = new Node(newVal);

        newNode->next = sum;
        sum = newNode;

        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }

    return sum;
}

int main() {
    Node* first = NULL;
    Node* second = NULL;

    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    push(&first, 5);
    push(&first, 7);

    push(&second, 4);
    push(&second, 8);

    Node* ans = addTwoLists(first, second);

    cout << "Sum is : ";
    printList(ans);

    return 0;
}