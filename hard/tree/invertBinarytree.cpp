#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void invertBinaryTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // Invert left and right subtrees first
    invertBinaryTree(root->left);
    invertBinaryTree(root->right);

    // Swap left and right children of the current node
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void printInOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    printInOrder(root->left);
    std::cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    std::cout << "Original Binary Tree (In-order traversal): ";
    printInOrder(root);
    std::cout << std::endl;

    invertBinaryTree(root);

    std::cout << "Inverted Binary Tree (In-order traversal): ";
    printInOrder(root);
    std::cout << std::endl;

    return 0;
}
