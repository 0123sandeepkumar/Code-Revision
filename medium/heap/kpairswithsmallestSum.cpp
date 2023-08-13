#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

struct PairSum {
    int sum;
    int idx1;
    int idx2;

    PairSum(int s, int i1, int i2) : sum(s), idx1(i1), idx2(i2) {}

    bool operator>(const PairSum& other) const {
        return sum > other.sum;
    }
};

vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<pair<int, int>> result;
    int m = nums1.size();
    int n = nums2.size();

    if (m == 0 || n == 0)
        return result;

    priority_queue<PairSum, vector<PairSum>, greater<PairSum>> minHeap;

    for (int i = 0; i < m && i < k; ++i) {
        minHeap.push(PairSum(nums1[i] + nums2[0], i, 0));
    }

    while (k-- > 0 && !minHeap.empty()) {
        PairSum ps = minHeap.top();
        minHeap.pop();
        result.push_back(make_pair(nums1[ps.idx1], nums2[ps.idx2]));

        if (ps.idx2 + 1 < n) {
            minHeap.push(PairSum(nums1[ps.idx1] + nums2[ps.idx2 + 1], ps.idx1, ps.idx2 + 1));
        }
    }

    return result;
}

int main() {
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    int k = 3;

    vector<pair<int, int>> pairs = kSmallestPairs(nums1, nums2, k);

    cout << "The " << k << " pairs with the smallest sums are:" << endl;
    for (const auto& pair : pairs) {
        cout << "(" << pair.first << ", " << pair.second << ")" << endl;
    }

    return 0;
}
