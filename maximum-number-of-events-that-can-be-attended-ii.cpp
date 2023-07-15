//problem: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/

//recursive dp + binary search

class Solution {
private:
    int my_upper_bound(vector<vector<int>>& events, int i) {
        int left = i + 1, right = events.size() - 1;
        int ret = events.size();
        while (left <= right) {
            int mid = (left + right) / 2;
            if (events[mid][0] > events[i][1]) {
                ret = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return ret;
    }
    int solve(int i, int k, vector<vector<int>>& events, vector<vector<int>>& dp) {
        if (i >= events.size() or k < 0) return 0;
        if (dp[i][k] != -1) return dp[i][k];
        int next = my_upper_bound(events, i);
        dp[i][k] = max(solve(next, k - 1, events, dp) + events[i][2], solve(i + 1, k, events, dp));
        return dp[i][k];
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int len = events.size();
        sort(events.begin(), events.end());
        vector <vector<int>> dp(len, vector<int>(k, -1));
        return solve(0, k - 1, events, dp);
    }
};
