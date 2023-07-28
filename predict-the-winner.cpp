//problem: https://leetcode.com/problems/predict-the-winner/

//naive: O(2 ^ n)
class Solution {
private:
    int solve(int i, int j, vector<int>& nums) {
        if (i > j) return 0;
        return max(nums[i] - solve(i + 1, j , nums), nums[j] - solve(i, j - 1, nums));
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int sum = 0;
        for (int a : nums) sum += a;
        return solve(0, nums.size() - 1, nums) >= 0;
    }
};


//optimized with dp
class Solution {
private:
    int solve(int i, int j, vector<int>& nums, vector <vector<int>>& dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1e9) return dp[i][j];
        return dp[i][j] = max(nums[i] - solve(i + 1, j , nums, dp), nums[j] - solve(i, j - 1, nums, dp));
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int sum = 0;
        for (int a : nums) sum += a;
        int len = nums.size();
        vector <vector<int>> dp(len, vector <int>(len, -1e9));
        return solve(0, len - 1, nums, dp) >= 0;
    }
};
