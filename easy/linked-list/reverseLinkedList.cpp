#include <iostream>

// Define the Node structure for the singly linked list
struct ListNode {
    int value;
    ListNode* next;
    ListNode(int val) : value(val), next(nullptr) {}
};

// Function to reverse the linked list in-place
ListNode* reverseLinkedList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;

    while (current) {
        // Save the next node in the original list.
        ListNode* nextNode = current->next;

        // Change the direction of the pointer to the previous node.
        current->next = prev;

        // Move pointers to the next iteration.
        prev = current;
        current = nextNode;
    }

    // At this point, the 'prev' pointer will be pointing to the new head of the reversed list.
    return prev;
}

// Helper function to create a linked list from an array of values
ListNode* createLinkedList(int values[], int n) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < n; ++i) {
        ListNode* newNode = new ListNode(values[i]);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

// Helper function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        std::cout << current->value;
        if (current->next) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << " -> nullptr" << std::endl;
}

int main() {
    int values[] = {1, 2, 3, 4, 5};
    int n = sizeof(values) / sizeof(values[0]);

    ListNode* head = createLinkedList(values, n);

    std::cout << "Original Linked List: ";
    printLinkedList(head);

    ListNode* reversedHead = reverseLinkedList(head);

    std::cout << "Reversed Linked List: ";
    printLinkedList(reversedHead);

    // Clean up the linked lists (release memory)
    ListNode* temp;
    while (reversedHead) {
        temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }

    return 0;
}
