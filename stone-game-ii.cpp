//problem: https://leetcode.com/problems/stone-game-ii/

class Solution {
public:
    int dp[101][101];
    int solve(vector <int>& piles, int i, int m, int suf[]) {
        if (i == piles.size())
            return 0;
        if (i + 2 * m >= piles.size())
            return suf[i];
        if (dp[i][m])
            return dp[i][m];
        int mx = 0;
        for (int j = 1; j <= 2 * m; ++j) {
                mx = max(mx,  suf[i] - solve(piles, i + j, max(m, j), suf));
        }

        return dp[i][m] = mx;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        int suf[n];
        memset(suf, 0, sizeof suf);
        suf[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; --i)
            suf[i] = suf[i + 1] + piles[i];
        return solve(piles, 0, 1, suf);
    }
};
