#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSymmetricHelper(TreeNode* leftSubtree, TreeNode* rightSubtree) {
    if (leftSubtree == nullptr && rightSubtree == nullptr) {
        return true; // Both subtrees are null, so they are mirror images.
    }
    if (leftSubtree == nullptr || rightSubtree == nullptr) {
        return false; // One subtree is null, but the other is not, so they are not mirror images.
    }

    // Compare the values of the nodes and check the mirror images of subtrees.
    return (leftSubtree->val == rightSubtree->val) &&
           isSymmetricHelper(leftSubtree->left, rightSubtree->right) &&
           isSymmetricHelper(leftSubtree->right, rightSubtree->left);
}

bool isSymmetric(TreeNode* root) {
    if (root == nullptr) {
        return true; // An empty tree is considered symmetric.
    }

    // Check the mirror images of left and right subtrees.
    return isSymmetricHelper(root->left, root->right);
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    if (isSymmetric(root)) {
        std::cout << "The binary tree is symmetric." << std::endl;
    } else {
        std::cout << "The binary tree is not symmetric." << std::endl;
    }

    return 0;
}
