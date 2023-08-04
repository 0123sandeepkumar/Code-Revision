#include <iostream>
#include <unordered_map>

struct Node {
    int val;
    Node* next;
    Node* random;

    Node(int val) : val(val), next(nullptr), random(nullptr) {}
};

Node* copyRandomList(Node* head) {
    if (head == nullptr) {
        return nullptr; // Empty list
    }

    std::unordered_map<Node*, Node*> node_map;

    // First pass: Create copies of each node and store the mapping in the hashmap
    Node* current = head;
    while (current != nullptr) {
        node_map[current] = new Node(current->val);
        current = current->next;
    }

    // Second pass: Connect the copied nodes in the copied list
    current = head;
    while (current != nullptr) {
        node_map[current]->next = node_map[current->next];
        node_map[current]->random = node_map[current->random];
        current = current->next;
    }

    return node_map[head];
}

// Helper function to create a linked list with random pointers
Node* create_linked_list_with_random(int* values, int size, int* random_indices) {
    Node* head = nullptr;
    Node* tail = nullptr;

    std::unordered_map<int, Node*> index_to_node;

    // First pass: Create the nodes without setting the random pointers
    for (int i = 0; i < size; ++i) {
        Node* new_node = new Node(values[i]);
        if (!head) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
        index_to_node[i] = new_node;
    }

    // Second pass: Set the random pointers using the indices from the given array
    Node* current = head;
    for (int i = 0; i < size; ++i) {
        if (random_indices[i] >= 0) {
            current->random = index_to_node[random_indices[i]];
        }
        current = current->next;
    }

    return head;
}

// Helper function to print a linked list with random pointers
void print_linked_list_with_random(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << "Node: " << current->val;
        if (current->random != nullptr) {
            std::cout << ", Random: " << current->random->val;
        }
        std::cout << std::endl;
        current = current->next;
    }
}

int main() {
    int values[] = {1, 2, 3, 4, 5};
    int random_indices[] = {1, 3, -1, 2, 0};

    Node* head = create_linked_list_with_random(values, sizeof(values) / sizeof(values[0]), random_indices);
    std::cout << "Original linked list with random pointers:" << std::endl;
    print_linked_list_with_random(head);

    Node* copied_head = copyRandomList(head);
    std::cout << "Copied linked list with random pointers:" << std::endl;
    print_linked_list_with_random(copied_head);

    return 0;
}
