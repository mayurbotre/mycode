#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void removeDuplicates(struct Node* start) {

    unordered_set<int> seen;

    struct Node* curr = start;
    struct Node* prev = NULL;

    while (curr != NULL) {

        if (seen.find(curr->data) != seen.end()) {
            prev->next = curr->next;
            delete (curr);
        }
        else {
            seen.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
}

void printList(struct Node* node)
{
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {

    struct Node* start = new Node(10);

    start->next = new Node(12);
    start->next->next = new Node(11);
    start->next->next->next = new Node(11);
    start->next->next->next->next = new Node(12);
    start->next->next->next->next->next = new Node(11);
    start->next->next->next->next->next->next
        = new Node(10);

    printf("Linked list before removing duplicates : \n");
    printList(start);

    removeDuplicates(start);

    printf("\nLinked list after removing duplicates : \n");
    printList(start);

    return 0;
}