#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val <= l2->val) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    // Append remaining nodes, if any
    if (l1 != nullptr) {
        current->next = l1;
    } else if (l2 != nullptr) {
        current->next = l2;
    }

    return dummy->next;
}

// Helper function to create a linked list
ListNode* create_linked_list(int* values, int size) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int i = 0; i < size; ++i) {
        ListNode* new_node = new ListNode(values[i]);
        if (!head) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }
    return head;
}

// Helper function to print a linked list
void print_linked_list(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    int values1[] = {1, 2, 4};
    int values2[] = {1, 3, 4};

    ListNode* l1 = create_linked_list(values1, sizeof(values1) / sizeof(values1[0]));
    ListNode* l2 = create_linked_list(values2, sizeof(values2) / sizeof(values2[0]));

    std::cout << "List 1: ";
    print_linked_list(l1);

    std::cout << "List 2: ";
    print_linked_list(l2);

    ListNode* merged_list = mergeTwoLists(l1, l2);

    std::cout << "Merged list: ";
    print_linked_list(merged_list);

    return 0;
}
