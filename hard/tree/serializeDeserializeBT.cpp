#include <iostream>
#include <sstream>
#include <string>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::string serialize(TreeNode* root) {
    if (root == nullptr) {
        return "null";
    }

    return std::to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
}

TreeNode* deserializeHelper(std::stringstream& ss) {
    std::string token;
    std::getline(ss, token, ',');
    if (token == "null") {
        return nullptr;
    }

    TreeNode* root = new TreeNode(std::stoi(token));
    root->left = deserializeHelper(ss);
    root->right = deserializeHelper(ss);

    return root;
}

TreeNode* deserialize(std::string data) {
    std::stringstream ss(data);
    return deserializeHelper(ss);
}

void printPreOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    std::cout << root->val << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    std::cout << "Original Binary Tree (Pre-order traversal): ";
    printPreOrder(root);
    std::cout << std::endl;

    std::string serializedTree = serialize(root);
    std::cout << "Serialized Tree: " << serializedTree << std::endl;

    TreeNode* deserializedRoot = deserialize(serializedTree);

    std::cout << "Deserialized Binary Tree (Pre-order traversal): ";
    printPreOrder(deserializedRoot);
    std::cout << std::endl;

    return 0;
}
