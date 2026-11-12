#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int value) {
        val = value;
        next = NULL;
    }
};

ListNode* deleteDuplicates(ListNode* head) {
    
    ListNode* current = head;

    while (current != NULL && current->next != NULL) {
        
        if (current->val == current->next->val) {
            current->next = current->next->next;
        }
        else {
            current = current->next;
        }
    }

    return head;
}

void printList(ListNode* head) {
    
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
}

int main() {
    
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    cout << "Original List: ";
    printList(head);

    head = deleteDuplicates(head);

    cout << "\nAfter Removing Duplicates: ";
    printList(head);

    return 0;
}