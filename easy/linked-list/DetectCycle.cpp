#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* detectCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr; // No cycle if the list is empty or has only one node
    }

    ListNode* slow = head;
    ListNode* fast = head;

    // Move slow and fast pointers until they meet or fast reaches the end
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            // Cycle detected, reset slow to head and move both pointers at the same speed
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // Return the node where the cycle starts
        }
    }

    return nullptr; // No cycle found
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

// Helper function to create a cycle in the linked list
void create_cycle(ListNode* head, int pos) {
    ListNode* current = head;
    ListNode* cycle_start = nullptr;
    int count = 0;

    while (current->next != nullptr) {
        if (count == pos) {
            cycle_start = current;
        }
        current = current->next;
        count++;
    }

    if (cycle_start != nullptr) {
        current->next = cycle_start;
    }
}

int main() {
    int values[] = {3, 2, 0, -4};
    int pos = 1;

    ListNode* head = create_linked_list(values, sizeof(values) / sizeof(values[0]));
    create_cycle(head, pos);

    ListNode* cycle_start = detectCycle(head);

    if (cycle_start != nullptr) {
        std::cout << "Cycle detected. The cycle starts at node with value: " << cycle_start->val << std::endl;
    } else {
        std::cout << "No cycle detected." << std::endl;
    }

    return 0;
}
