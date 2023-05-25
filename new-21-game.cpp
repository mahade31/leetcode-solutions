//problem: https://leetcode.com/problems/new-21-game

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0) return 1;
        if (k == 1 and maxPts <= n) return 1;

        int mx = maxPts + k - 1;

        double dp[mx + 1];
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        double sum = 1;
        double ret = 0;

        for (int i = 1; i <= min(mx, n); ++i) {
            dp[i] = sum / maxPts;
            if (i < k)
                sum += dp[i];
            else
                ret += dp[i];
            
            if (i - maxPts >= 0)
                sum -= dp[i - maxPts];
        }

        return ret;
    }
};
