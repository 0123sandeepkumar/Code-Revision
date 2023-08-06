#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

std::string simplifyPath(std::string path) {
    std::stack<std::string> stk;
    std::stringstream ss(path);
    std::string token;

    while (getline(ss, token, '/')) {
        if (token.empty() || token == ".") {
            // Skip empty strings and "."
            continue;
        } else if (token == "..") {
            // If we encounter "..", pop the top element from the stack if it's not empty
            if (!stk.empty()) {
                stk.pop();
            }
        } else {
            // Push valid path components onto the stack
            stk.push(token);
        }
    }

    // Reconstruct the simplified path from the stack
    std::vector<std::string> components;
    while (!stk.empty()) {
        components.push_back(stk.top());
        stk.pop();
    }

    // Construct the simplified path in reverse order
    std::stringstream simplified_path;
    for (int i = components.size() - 1; i >= 0; --i) {
        simplified_path << "/" << components[i];
    }

    // Handle the case when the original path was just "/"
    if (simplified_path.str().empty()) {
        simplified_path << "/";
    }

    return simplified_path.str();
}

int main() {
    std::string path = "/a/./b/../../c/";
    std::string simplified_path = simplifyPath(path);
    std::cout << "Simplified Path: " << simplified_path << std::endl;
    return 0;
}
