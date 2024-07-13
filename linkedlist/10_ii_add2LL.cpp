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

Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* prev = NULL;

    stack<Node*> s1, s2, s3;

    while (l1 != NULL) {
        s1.push(l1);
        l1 = l1->next;
    }

    while (l2 != NULL) {
        s2.push(l2);
        l2 = l2->next;
    }
    int carry = 0;

    while (!s1.empty() && !s2.empty()) {
        int sum = s1.top()->data + s2.top()->data + carry;
        Node* temp = new Node(sum % 10);
        s3.push(temp);
        if (sum > 9) {
            carry = 1;
        }
        else {
            carry = 0;
        }
        s1.pop();
        s2.pop();
    }
    while (!s1.empty()) {
        int sum = carry + s1.top()->data;
        Node* temp = new Node(sum % 10);
        s3.push(temp);
        if (sum > 9) {
            carry = 1;
        }
        else {
            carry = 0;
        }
        s1.pop();
    }
    while (!s2.empty()) {
        int sum = carry + s2.top()->data;
        Node* temp = new Node(sum % 10);
        s3.push(temp);
        if (sum > 9) {
            carry = 1;
        }
        else {
            carry = 0;
        }
        s2.pop();
    }

    if (carry == 1) {
        Node* temp = new Node(1);
        s3.push(temp);
    }

    if (!s3.empty())
        prev = s3.top();
    while (!s3.empty()) {
        Node* temp = s3.top();
        s3.pop();
        if (s3.size() == 0) {
            temp->next = NULL;
        }
        else {
            temp->next = s3.top();
        }
    }
    return prev;
}


void Display(Node* head) {
    if (head == NULL) {
        return;
    }
    while (head->next != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << head->data << endl;
}

void push(Node** head_ref, int d) {
    Node* new_node = new Node(d);
    new_node->next = NULL;
    if (*head_ref == NULL) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }
    Node* last = *head_ref;
    while (last->next != NULL && last != NULL) {
        last = last->next;
    }
    last->next = new_node;
    return;
}

int main() {

    Node* first = NULL;
    Node* second = NULL;
    Node* sum = NULL;

    push(&first, 7);
    push(&first, 5);
    push(&first, 9);
    push(&first, 4);
    push(&first, 6);
    push(&second, 8);
    push(&second, 4);

    cout << "First List : ";
    Display(first);

    cout << "Second List : ";
    Display(second);

    sum = addTwoNumbers(first, second);

    cout << "Sum List : ";
    Display(sum);

    return 0;
}
