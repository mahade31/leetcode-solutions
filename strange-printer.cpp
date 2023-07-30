//problem: https://leetcode.com/problems/strange-printer/

class Solution {
private:
    int solve(int i, int j, vector <vector<int>>& dp, string& s) {
        if (i == j) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        int ret = 1e9;
        for (int k = i; k < j; ++k) ret = min(ret, solve(i, k, dp, s) + solve(k + 1, j, dp, s));
        return dp[i][j] = (s[i] == s[j] ? ret - 1 : ret);
    }
public:
    int strangePrinter(string s) {
        int len = s.size();
        vector <vector<int>> dp(len, vector<int>(len, -1));

        return solve(0, len - 1, dp, s);
    }
};
