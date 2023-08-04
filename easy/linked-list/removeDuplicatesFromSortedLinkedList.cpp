#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) {
        return nullptr; // Empty list
    }

    ListNode* current = head;

    while (current->next != nullptr) {
        if (current->val == current->next->val) {
            // Duplicate found, remove the duplicate node
            ListNode* to_be_deleted = current->next;
            current->next = current->next->next;
            delete to_be_deleted;
        } else {
            // Move to the next node if no duplicate is found
            current = current->next;
        }
    }

    return head;
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
    int values[] = {1, 1, 2, 3, 3};

    ListNode* head = create_linked_list(values, sizeof(values) / sizeof(values[0]));
    std::cout << "Original linked list: ";
    print_linked_list(head);

    ListNode* distinct_list = deleteDuplicates(head);
    std::cout << "Distinct linked list: ";
    print_linked_list(distinct_list);

    return 0;
}
