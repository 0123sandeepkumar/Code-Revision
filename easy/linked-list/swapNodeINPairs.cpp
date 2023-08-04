#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;

    while (head != nullptr && head->next != nullptr) {
        ListNode* first = head;
        ListNode* second = head->next;

        // Swap the two adjacent nodes
        prev->next = second;
        first->next = second->next;
        second->next = first;

        // Move to the next pair of nodes
        prev = first;
        head = first->next;
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
    int values[] = {1, 2, 3, 4, 5};

    ListNode* head = create_linked_list(values, sizeof(values) / sizeof(values[0]));
    std::cout << "Original linked list: ";
    print_linked_list(head);

    ListNode* swapped_list = swapPairs(head);
    std::cout << "Swapped linked list: ";
    print_linked_list(swapped_list);

    return 0;
}
