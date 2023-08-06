#include <iostream>
#include <stack>
#include <vector>
#include <sstream>

int calPoints(std::vector<std::string>& ops) {
    std::stack<int> scoreStack;

    for (const std::string& op : ops) {
        if (op == "C") {
            // Remove the last valid score
            if (!scoreStack.empty()) {
                scoreStack.pop();
            }
        } else if (op == "D") {
            // Double the last valid score and push it onto the stack
            if (!scoreStack.empty()) {
                int prevScore = scoreStack.top();
                scoreStack.push(prevScore * 2);
            }
        } else if (op == "+") {
            // Add the sum of the last two valid scores and push it onto the stack
            if (scoreStack.size() >= 2) {
                int prevScore1 = scoreStack.top();
                scoreStack.pop();
                int prevScore2 = scoreStack.top();
                int currentScore = prevScore1 + prevScore2;
                scoreStack.push(prevScore1);
                scoreStack.push(currentScore);
            }
        } else {
            // Convert the string to an integer and push it onto the stack
            int score;
            std::stringstream ss(op);
            ss >> score;
            scoreStack.push(score);
        }
    }

    int totalScore = 0;
    while (!scoreStack.empty()) {
        totalScore += scoreStack.top();
        scoreStack.pop();
    }

    return totalScore;
}

int main() {
    std::vector<std::string> ops = {"5", "2", "C", "D", "+"};
    int totalScore = calPoints(ops);
    std::cout << "Total Score: " << totalScore << std::endl;
    return 0;
}
