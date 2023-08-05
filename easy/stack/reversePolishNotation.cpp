#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// A helper function to check if a string is an operator
bool isOperator(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

// A helper function to perform an arithmetic operation
int operate(int a, int b, const string& op) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") return a / b;
    return 0; // invalid operator
}

// A function to evaluate reverse Polish notation using a stack
int evalRPN(const vector<string>& tokens) {
    stack<int> st; // create an empty stack
    for (const string& token : tokens) { // iterate over the tokens
        if (isOperator(token)) { // if the token is an operator
            int b = st.top(); st.pop(); // pop the top two operands from the stack
            int a = st.top(); st.pop();
            int c = operate(a, b, token); // perform the operation and get the result
            st.push(c); // push the result back to the stack
        } else { // if the token is an operand
            int x = stoi(token); // convert the token to an integer
            st.push(x); // push it to the stack
        }
    }
    return st.top(); // return the final result from the stack
}

// A main function to test the code
int main() {
    vector<string> tokens = {"2", "1", "+", "3", "*"}; // an example expression in reverse Polish notation
    cout << evalRPN(tokens) << endl; // should print 9
    return 0;
}
