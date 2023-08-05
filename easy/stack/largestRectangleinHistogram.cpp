#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    int max_area = 0;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && heights[i] < heights[st.top()]) {
            int height = heights[st.top()];
            st.pop();

            int width = st.empty() ? i : i - st.top() - 1;
            max_area = max(max_area, height * width);
        }
        st.push(i);
    }

    while (!st.empty()) {
        int height = heights[st.top()];
        st.pop();

        int width = st.empty() ? n : n - st.top() - 1;
        max_area = max(max_area, height * width);
    }

    return max_area;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int max_area = largestRectangleArea(heights);
    cout << "The largest rectangle area in the histogram is: " << max_area << endl;
    return 0;
}
