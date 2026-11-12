#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int value) {
        val = value;
        next = NULL;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {

    vector<int> numbers;

    for (ListNode* head : lists) {

        while (head != NULL) {
            numbers.push_back(head->val);
            head = head->next;
        }
    }

    sort(numbers.begin(), numbers.end());

    ListNode* head = NULL;
    ListNode* tail = NULL;

    for (int num : numbers) {

        ListNode* newNode = new ListNode(num);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
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

    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* list3 = new ListNode(2);
    list3->next = new ListNode(6);

    vector<ListNode*> lists = {list1, list2, list3};

    ListNode* result = mergeKLists(lists);

    cout << "Merged List: ";
    printList(result);

    return 0;
}