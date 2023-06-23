//problem: https://leetcode.com/problems/longest-arithmetic-subsequence/

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int dp[n][1003];
        memset (dp, 0, sizeof dp);
        int ret = 0;
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                int diff = nums[j] - nums[i] + 500;
                dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
                ret = max(ret, dp[i][diff]);
            }
        }
        return ret + 1;
    }
};
