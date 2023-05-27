//problem: https://leetcode.com/problems/stone-game-iii/

class Solution {
public:
int dp[50004][5];
    int solve(vector <int>& piles, int i, int m, int suf[]) {
        if (i == piles.size())
            return 0;
        if (i + m >= piles.size())
            return suf[i];
        if (dp[i][m] != 1e9)
            return dp[i][m];
        int mx = 0;
        for (int j = 1; j <= m; ++j) {
                mx = max(mx,  suf[i] - solve(piles, i + j, 3, suf));
        }

        return dp[i][m] = mx;
    }
    string stoneGameIII(vector<int>& piles) {
        int n = piles.size();
        int suf[n];
        memset(suf, 0, sizeof suf);
        for (int i = 0; i < 50004; ++i){
            for (int j = 0; j <= 3; ++j){
                dp[i][j] = 1e9;
            }
        }
        suf[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; --i)
            suf[i] = suf[i + 1] + piles[i];
        int alice = solve(piles, 0, 3, suf);
        int bob = suf[0] - alice;

        if (alice > bob)
            return "Alice";
        else if (bob > alice)
            return "Bob";
        else
            return "Tie";
    }
};

