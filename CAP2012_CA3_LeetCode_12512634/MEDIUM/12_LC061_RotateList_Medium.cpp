#include <iostream>
using namespace std;

// Node banana
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int value) {
        val = value;
        next = NULL;
    }
};

ListNode* rotateRight(ListNode* head, int k) {

    if (head == NULL || head->next == NULL) {
        return head;
    }

    for (int j = 0; j < k; j++) {

        ListNode* current = head;

        while (current->next->next != NULL) {
            current = current->next;
        }

        ListNode* last = current->next;

        current->next = NULL;

        last->next = head;
        head = last;
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
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    cout << "Original List: ";
    printList(head);

    head = rotateRight(head, k);

    cout << "\nRotated List: ";
    printList(head);

    return 0;
}