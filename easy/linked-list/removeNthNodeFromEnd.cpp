#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* first = dummy;
    ListNode* second = dummy;

    // Move the first pointer n+1 steps ahead
    for (int i = 0; i <= n; ++i) {
        first = first->next;
    }

    // Move both pointers simultaneously
    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }

    // Remove the nth node from the end
    ListNode* to_be_deleted = second->next;
    second->next = second->next->next;
    delete to_be_deleted;

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
    int values[] = {1, 2, 3, 4, 5};
    int n = 2;

    ListNode* head = create_linked_list(values, sizeof(values) / sizeof(values[0]));
    std::cout << "Original linked list: ";
    print_linked_list(head);

    ListNode* modified_head = removeNthFromEnd(head, n);
    std::cout << "Modified linked list: ";
    print_linked_list(modified_head);

    return 0;
}
