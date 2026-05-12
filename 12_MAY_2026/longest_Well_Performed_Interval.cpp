#include <bits/stdc++.h>
using namespace std;

// LeetCode 1124: longest subarray with sum > 0 on score[i] = (hours[i] > 8) ? 1 : -1
// Prefix P[0]=0, P[j]=sum(score[0..j-1]). Subarray L..R has sum P[R+1]-P[L]; want P[R+1] > P[L].
// Phase 1: stack of indices with strictly decreasing P (candidate left endpoints).
// Phase 2: scan j from n down to 0; while P[j] > P[stack.top], pop and maximize j - index.
int longestWPI(vector<int>& hours) {
    int n = (int)hours.size();
    vector<int> p(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int s = (hours[i] > 8) ? 1 : -1;
        p[i + 1] = p[i] + s;
    }

    vector<int> stk;
    stk.reserve(n + 1);
    for (int i = 0; i <= n; ++i) {
        if (stk.empty() || p[i] < p[stk.back()]) {
            stk.push_back(i);
        }
    }

    int ans = 0;
    for (int j = n; j >= 0; --j) {
        while (!stk.empty() && p[j] > p[stk.back()]) {
            ans = max(ans, j - stk.back());
            stk.pop_back();
        }
    }
    return ans;
}

int main() {
    vector<int> hours = {9, 9, 6, 0, 6, 6, 9};
    cout << longestWPI(hours) << endl;  // 3

    vector<int> hours2 = {6, 6, 6};
    cout << longestWPI(hours2) << endl;  // 0
}
