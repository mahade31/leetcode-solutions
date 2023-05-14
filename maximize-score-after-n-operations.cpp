//problem: https://leetcode.com/problems/maximize-score-after-n-operations

class Solution {
public:
    int solve(int n, int len, int mask, int dp[], vector<int>& nums){
        if (len == 0)
            return 0;
        if (dp[mask] != -1)
            return dp[mask];
        int ret = 0;
        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j){
                if ((mask & (1 << (i + 1))) or (mask & (1 << (j + 1))))
                    continue;
                int score = len * __gcd(nums[i], nums[j]);
                score += solve(n, len - 1, mask | (1 << (i + 1)) | (1 << (j + 1)), dp, nums);
                ret = max(ret, score);
            }
        }
        return dp[mask] = ret;
    }
    int maxScore(vector<int>& nums) {
        int dp[(1 << 16)];
        memset(dp, -1, sizeof dp);
        return solve(nums.size(), nums.size() / 2, 0, dp, nums);
    }
};
