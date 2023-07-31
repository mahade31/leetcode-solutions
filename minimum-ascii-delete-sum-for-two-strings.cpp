//problem: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

class Solution {
private:
    int solve(int i, int j, string& s, string& t, vector <vector<int>>& dp) {
        if (i >= s.size() and j >= t.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int ret = 1e9;
        if (i >= s.size()) ret = t[j] + solve(i, j + 1, s, t, dp);
        else if (j >= t.size()) ret = s[i] + solve(i + 1, j, s, t, dp);
        else if (s[i] == t[j]) ret = solve(i + 1, j + 1, s, t, dp);
        else {
            ret = min(s[i] + t[j] + solve(i + 1, j + 1, s, t, dp), 
                    min(s[i] + solve(i + 1, j, s, t, dp), t[j] + solve(i, j + 1, s, t, dp)));
        }
        return dp[i][j] = ret;
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector <vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        return solve(0, 0, s1, s2, dp);
    }
};
