//problem: https://leetcode.com/problems/tallest-billboard


class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int len = rods.size();
        int dp[len + 1][5001];
        memset (dp, -1, sizeof dp);
        dp[0][0] = 0;

        for (int i = 1; i <= len; ++i) {
            for (int j = 0; j < 5001; ++j) {
                if (dp[i - 1][j] == -1) continue;

                int right = dp[i-1][j];
                int left = right - j;

                int new_left = left + rods[i-1];
                int cur = dp[i][abs(new_left - right)];
                dp[i][abs(new_left - right)] = max(max(new_left, right), cur);

                int new_right = right + rods[i-1];
                cur = dp[i][new_right - left];
                dp[i][new_right - left] = max(new_right, cur);

                cur = dp[i][j];
                dp[i][j] = max(dp[i-1][j], cur);
            }
        }
        return dp[len][0];
    }
};
