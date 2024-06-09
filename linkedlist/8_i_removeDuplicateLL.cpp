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

void removeDuplicates(struct Node* start) {
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = start;

    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;

        while (ptr2->next != NULL) {
            
            if (ptr1->data == ptr2->next->data) {
               
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
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
    start->next->next->next->next->next->next = new Node(10);

    printf("Linked list before removing duplicates ");
    printList(start);

    removeDuplicates(start);

    printf("\nLinked list after removing duplicates ");
    printList(start);
    return 0;
}