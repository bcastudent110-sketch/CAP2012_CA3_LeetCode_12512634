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

ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* current = head;

    while (current != NULL) {
        ListNode* next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }

    return prev;
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    head = reverseList(head);

    cout << "\nReversed List: ";
    printList(head);

    return 0;
}