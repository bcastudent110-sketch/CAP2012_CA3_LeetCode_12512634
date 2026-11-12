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

ListNode* reverseBetween(ListNode* head, int left, int right) {

    if (left == right) {
        return head;
    }

    ListNode* current = head;
    ListNode* before = NULL;

    for (int i = 1; i < left; i++) {
        before = current;
        current = current->next;
    }

    ListNode* start = current;
    ListNode* prev = NULL;

    for (int i = left; i <= right; i++) {
        ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    if (before != NULL) {
        before->next = prev;
    }
    else {
        head = prev;
    }

    start->next = current;

    return head;
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
}

int main() {

    // List: 1 → 2 → 3 → 4 → 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int left = 2;
    int right = 4;

    cout << "Original List: ";
    printList(head);

    head = reverseBetween(head, left, right);

    cout << "\nReversed List: ";
    printList(head);

    return 0;
}