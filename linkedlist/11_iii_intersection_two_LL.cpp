#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x)
        : data(x)
        , next(NULL)
    {
    }
};

Node* findIntersection(Node* a, Node* b){
    if (a == NULL || b == NULL) {
        return NULL;
    }
    if (a->data < b->data) {
        return findIntersection(a->next, b);
    }
    else if (a->data > b->data) {
        return findIntersection(a, b->next);
    }
    else {
        Node* temp = new Node(a->data);
        temp->next = findIntersection(a->next, b->next);
        return temp;
    }
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
    while (result != NULL) {
        cout << result->data << " ";
        result = result->next;
    }
    return 0;
}
