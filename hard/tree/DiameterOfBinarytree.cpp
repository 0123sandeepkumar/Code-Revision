#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int height(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return std::max(height(root->left), height(root->right)) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftDiameter = diameterOfBinaryTree(root->left);
    int rightDiameter = diameterOfBinaryTree(root->right);

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Diameter is the maximum of (leftDiameter, rightDiameter, leftHeight + rightHeight + 1)
    return std::max({leftDiameter, rightDiameter, leftHeight + rightHeight + 1});
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);

    int diameter = diameterOfBinaryTree(root);

    std::cout << "Diameter of the binary tree: " << diameter << std::endl;

    return 0;
}
