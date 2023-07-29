#include <iostream>
#include <climits>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isValidBSTHelper(TreeNode* root, long long& prev) {
    if (root == nullptr) {
        return true;
    }

    // Check left subtree
    if (!isValidBSTHelper(root->left, prev)) {
        return false;
    }

    // Check current node
    if (root->val <= prev) {
        return false;
    }
    prev = root->val;

    // Check right subtree
    return isValidBSTHelper(root->right, prev);
}

bool isValidBST(TreeNode* root) {
    long long prev = LLONG_MIN;
    return isValidBSTHelper(root, prev);
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    if (isValidBST(root)) {
        std::cout << "The binary tree is a valid binary search tree (BST)." << std::endl;
    } else {
        std::cout << "The binary tree is not a valid binary search tree (BST)." << std::endl;
    }

    return 0;
}
