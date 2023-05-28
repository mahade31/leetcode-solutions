//problem: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/


class Solution {
public:
    int solve(int i, int j, int k, int l, vector<int>& cuts, vector<vector<int>>& dp) {
        if (k == l) 
            return 0;
        if (dp[k][l] != -1)
            return dp[k][l];

        int ret = 1e9;
        for (int m = k; m < l; ++m) {
            ret = min(ret, j - i + solve(i, cuts[m], k, m, cuts, dp) + 
                                solve(cuts[m], j, m + 1, l, cuts, dp));
        }
        return dp[k][l] = ret;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        vector <vector<int>> dp;
        for (int i = 0; i <= (int)cuts.size(); ++i) {
            vector <int> temp((int)cuts.size() + 1, -1);
            dp.push_back(temp);
        }
        return solve(0, n, 0, cuts.size(), cuts, dp);
    }
};
