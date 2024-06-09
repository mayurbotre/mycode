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

void hashAndRemove(Node* head) {
    
    unordered_map<Node*, int> node_map;
   
    Node* last = NULL;
    while (head != NULL) {
        
        if (node_map.find(head) == node_map.end()) {
            node_map[head]++;
            last = head;
            head = head->next;
        }
        
        else {
            last->next = NULL;
            break;
        }
    }
}

int main() {

    Node* head = new Node(50);

    head->next = new Node(20);
    head->next->next = new Node(15);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(10);

    head->next->next->next->next->next = head->next->next;

    hashAndRemove(head);

    printf("Linked List after removing loop \n");
    printList(head);

    return 0;
}