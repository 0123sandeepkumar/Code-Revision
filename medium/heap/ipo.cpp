#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Project {
    int profit;
    int capital;

    Project(int p, int c) : profit(p), capital(c) {}
};

class CompareByCapital {
public:
    bool operator()(const Project& p1, const Project& p2) {
        return p1.capital > p2.capital;
    }
};

class CompareByProfit {
public:
    bool operator()(const Project& p1, const Project& p2) {
        return p1.profit < p2.profit;
    }
};

int findMaximizedCapital(int k, int initialCapital, vector<int>& profits, vector<int>& capital) {
    vector<Project> projects;
    for (int i = 0; i < profits.size(); ++i) {
        projects.push_back(Project(profits[i], capital[i]));
    }

    priority_queue<Project, vector<Project>, CompareByCapital> minCapitalHeap;
    priority_queue<Project, vector<Project>, CompareByProfit> maxProfitHeap;

    for (const Project& project : projects) {
        minCapitalHeap.push(project);
    }

    while (k > 0) {
        while (!minCapitalHeap.empty() && minCapitalHeap.top().capital <= initialCapital) {
            maxProfitHeap.push(minCapitalHeap.top());
            minCapitalHeap.pop();
        }

        if (maxProfitHeap.empty()) {
            break;
        }

        initialCapital += maxProfitHeap.top().profit;
        maxProfitHeap.pop();
        k--;
    }

    return initialCapital;
}

int main() {
    int k = 2;
    int initialCapital = 0;
    vector<int> profits = {1, 2, 3};
    vector<int> capital = {0, 1, 1};

    int maxProfit = findMaximizedCapital(k, initialCapital, profits, capital);

    cout << "Maximized total profit: " << maxProfit << endl;

    return 0;
}
