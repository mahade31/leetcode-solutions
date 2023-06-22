//problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

class Solution {
public:
    int solve(int i, bool f, vector<int>& prices, int fee, vector<vector<int>>& dp) {
        if (i >= dp.size()) return 0;
        if (dp[i][f] != -1) return dp[i][f];
        int buy_or_skip = max(f ? solve(i + 1, !f, prices, fee, dp) - prices[i] : -1, 
                            solve(i + 1, f, prices, fee, dp));
        int sell = f ? -1 : prices[i] - fee + solve(i + 1, !f, prices, fee, dp);
        dp[i][f] = max(buy_or_skip, sell);
        return dp[i][f];
    }

    int maxProfit(vector<int>& prices, int fee) {
        vector <vector<int>> dp;
        for (int i = 0; i < prices.size(); ++i) dp.push_back({-1, -1});
        return solve(0, true , prices, fee, dp);
    }
};
