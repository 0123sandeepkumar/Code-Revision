#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev_group_end = dummy;

    while (head != nullptr) {
        // Check if there are enough nodes in the group to reverse
        ListNode* group_end = prev_group_end;
        for (int i = 0; i < k; ++i) {
            group_end = group_end->next;
            if (group_end == nullptr) {
                // Less than k nodes left, no need to reverse
                return dummy->next;
            }
        }

        // Reverse the k nodes in the group
        ListNode* group_start = prev_group_end->next;
        ListNode* next_group_start = group_end->next;
        ListNode* prev = next_group_start;
        ListNode* current = group_start;

        while (current != next_group_start) {
            ListNode* next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }

        // Connect the reversed group to the previous group
        prev_group_end->next = group_end;
        group_start->next = next_group_start;

        // Move to the next group
        prev_group_end = group_start;
        head = next_group_start;
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
    int values[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int k = 3;

    ListNode* head = create_linked_list(values, sizeof(values) / sizeof(values[0]));
    std::cout << "Original linked list: ";
    print_linked_list(head);

    ListNode* reversed_list = reverseKGroup(head, k);
    std::cout << "Reversed linked list in groups of " << k << ": ";
    print_linked_list(reversed_list);

    return 0;
}
