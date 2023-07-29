#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int countNodes(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = 0, rightHeight = 0;
    TreeNode* leftNode = root, * rightNode = root;

    // Find the height of the left and right subtrees
    while (leftNode) {
        leftHeight++;
        leftNode = leftNode->left;
    }
    while (rightNode) {
        rightHeight++;
        rightNode = rightNode->right;
    }

    // If left and right heights are the same, it means the left subtree is perfect
    if (leftHeight == rightHeight) {
        return (1 << leftHeight) - 1; // 2^leftHeight - 1
    }

    // If left and right heights are different, the right subtree is also complete
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    int numNodes = countNodes(root);

    std::cout << "Number of nodes in the complete binary tree: " << numNodes << std::endl;

    return 0;
}
