#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x){
        this->val = x;
        this->next = NULL;
    }
};

ListNode* detectCycle(ListNode* A) {
    unordered_set<ListNode*> uset;
    ListNode *ptr = A;

    while (ptr != NULL) {
        if (uset.find(ptr) != uset.end()) return ptr;
        else uset.insert(ptr); 
        ptr = ptr->next;
    }
    return NULL;
}

int main() {
    ListNode* head = new ListNode(50);
    head->next = new ListNode(20);
    head->next->next = new ListNode(15);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(10);
  
    head->next->next->next->next->next = head->next->next;
  
    ListNode* res = detectCycle(head);
    if (res == NULL)
        cout << "Loop does not exist";
    else
        cout << "Loop starting node is " << res->val;
  
    return 0;
}