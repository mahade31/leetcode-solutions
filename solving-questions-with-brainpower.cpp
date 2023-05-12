//problem: https://leetcode.com/problems/solving-questions-with-brainpower/

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int len = questions.size();
        long long dp[len];
        dp[len - 1] = questions[len - 1][0];
        for (int i = len - 2; i >= 0; --i){
            int j = i + 1 + questions[i][1];
            if (j >= len){
                dp[i] = max(1LL*questions[i][0], dp[i + 1]);
            }
            else {
                dp[i] = max(dp[i + 1], dp[j] + questions[i][0]);
            }
        }
        return dp[0];
    }
};
