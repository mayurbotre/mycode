#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node* findIntersection(Node* head1, Node* head2){
    Node *p1 = head1, *p2 = head2;
    Node *head = NULL, *tail = NULL;

    while (p1 && p2) {
        if (p1->data > p2->data) {
            p2 = p2->next;
        }
        else if (p2->data > p1->data) {
            p1 = p1->next;
        }
        else {
            if (head == NULL) {
                head = tail = new Node(p1->data);
            }
            else {
                tail->next = new Node(p1->data);
                tail = tail->next;
            }

            p1 = p1->next;
            p2 = p2->next;
        }
    }

    return head;
}

int main(){

    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(6);

    Node* head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);
    head2->next->next->next = new Node(8);

    Node* result = findIntersection(head1, head2);

    while (result) {
        cout << result->data << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}