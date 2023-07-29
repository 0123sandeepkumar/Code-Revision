#include <iostream>
#include <vector>
#include <string>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void binaryTreePathsHelper(TreeNode* root, std::vector<std::string>& paths, std::string currentPath) {
    if (root == nullptr) {
        return;
    }

    currentPath += std::to_string(root->val);

    if (root->left == nullptr && root->right == nullptr) {
        // We have reached a leaf node, so add the current path to the list of paths
        paths.push_back(currentPath);
        return;
    }

    currentPath += "->";

    binaryTreePathsHelper(root->left, paths, currentPath);
    binaryTreePathsHelper(root->right, paths, currentPath);
}

std::vector<std::string> binaryTreePaths(TreeNode* root) {
    std::vector<std::string> paths;
    binaryTreePathsHelper(root, paths, "");
    return paths;
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    std::vector<std::string> paths = binaryTreePaths(root);

    std::cout << "Root-to-Leaf Paths:" << std::endl;
    for (const std::string& path : paths) {
        std::cout << path << std::endl;
    }

    return 0;
}
