#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) {
        return root;
    }

    TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

    if (leftLCA && rightLCA) {
        // Both nodes are found in the left and right subtrees, so root is the LCA.
        return root;
    }

    // Either both nodes are in the left subtree or both are in the right subtree.
    // Return the non-null LCA (if found) from either the left or right subtree.
    return leftLCA ? leftLCA : rightLCA;
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* node1 = root->left; // Node with value 5
    TreeNode* node2 = root->right; // Node with value 1

    TreeNode* lca = lowestCommonAncestor(root, node1, node2);

    std::cout << "Lowest Common Ancestor: " << lca->val << std::endl;

    return 0;
}
