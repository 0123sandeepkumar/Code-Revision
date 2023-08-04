#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (headA == nullptr || headB == nullptr) {
        return nullptr;
    }

    int len1 = 0;
    int len2 = 0;
    ListNode* curr1 = headA;
    ListNode* curr2 = headB;

    // Find the lengths of both linked lists
    while (curr1 != nullptr) {
        len1++;
        curr1 = curr1->next;
    }

    while (curr2 != nullptr) {
        len2++;
        curr2 = curr2->next;
    }

    // Calculate the difference in lengths
    int diff = abs(len1 - len2);

    // Move the pointer of the longer list 'diff' steps forward
    curr1 = headA;
    curr2 = headB;
    if (len1 > len2) {
        while (diff > 0) {
            curr1 = curr1->next;
            diff--;
        }
    } else if (len2 > len1) {
        while (diff > 0) {
            curr2 = curr2->next;
            diff--;
        }
    }

    // Traverse both lists until they intersect
    while (curr1 != nullptr && curr2 != nullptr) {
        if (curr1 == curr2) {
            return curr1;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return nullptr; // No intersection found
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
    int values1[] = {4, 1, 8, 4, 5};
    int values2[] = {5, 6, 1, 8, 4, 5};
    int intersection_pos = 2;

    ListNode* headA = create_linked_list(values1, sizeof(values1) / sizeof(values1[0]));
    ListNode* headB = create_linked_list(values2, sizeof(values2) / sizeof(values2[0]));

    // Create the intersection at the specified position
    ListNode* curr1 = headA;
    for (int i = 0; i < intersection_pos; ++i) {
        curr1 = curr1->next;
    }
    ListNode* curr2 = headB;
    while (curr2->next != nullptr) {
        curr2 = curr2->next;
    }
    curr2->next = curr1;

    ListNode* intersection = getIntersectionNode(headA, headB);

    if (intersection != nullptr) {
        std::cout << "Intersection found at node with value: " << intersection->val << std::endl;
    } else {
        std::cout << "No intersection found." << std::endl;
    }

    return 0;
}
