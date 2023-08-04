#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

// Function to reverse a linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;

    while (current != nullptr) {
        ListNode* next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }

    return prev;
}

bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return true; // An empty list or a list with a single node is a palindrome
    }

    ListNode* slow = head;
    ListNode* fast = head;

    // Find the middle of the linked list using the slow and fast pointer technique
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // If the length of the linked list is odd, move slow one step ahead
    if (fast != nullptr) {
        slow = slow->next;
    }

    // Reverse the second half of the linked list
    ListNode* reversed_second_half = reverseList(slow);

    // Compare the first half with the reversed second half
    ListNode* current = head;
    while (reversed_second_half != nullptr) {
        if (current->val != reversed_second_half->val) {
            return false;
        }
        current = current->next;
        reversed_second_half = reversed_second_half->next;
    }

    return true;
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

int main() {
    int values[] = {1, 2, 3, 2, 1};

    ListNode* head = create_linked_list(values, sizeof(values) / sizeof(values[0]));
    bool is_palindrome = isPalindrome(head);

    if (is_palindrome) {
        std::cout << "The linked list is a palindrome." << std::endl;
    } else {
        std::cout << "The linked list is not a palindrome." << std::endl;
    }

    return 0;
}
