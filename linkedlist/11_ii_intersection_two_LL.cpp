#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr)
    {
    }
};

Node* findIntersection(Node* head1, Node* head2){
    unordered_map<int, int> set;
    Node* dummy = new Node(0);
    Node* curr = dummy;
    while (head1 != nullptr) {
        set[head1->data]++;
        head1 = head1->next;
    }
    while (head2 != nullptr) {
        if (set.count(head2->data)) {
            set[head2->data]--;
            if (set[head2->data] == 0) {
                set.erase(head2->data);
            }
            curr->next = new Node(head2->data);
            curr = curr->next;
        }
        head2 = head2->next;
    }
    Node* result = dummy->next;
    delete dummy;
    return result;
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

    while (result != nullptr) {
        cout << result->data << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}