//problem: https://leetcode.com/problems/count-all-possible-routes/

class Solution {
private:
    int solve(vector<int>& locations, int cur, int finish, int fuel, vector<vector<int>>& dp) {
        if (fuel < 0) return 0;
        if (dp[cur][fuel] != -1) return dp[cur][fuel];
        int ret = (cur == finish) ? 1 : 0;

        for (int i = 0; i < locations.size(); ++i) {
            if (cur != i) {
                ret += solve(locations, i, finish, fuel - abs(locations[cur] - locations[i]), dp);
                ret %= 1000000007;
            }
        }
        return dp[cur][fuel] = ret;
    }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int len = locations.size();
        vector <vector<int>> dp(len, vector<int>(fuel + 1, -1));
        return solve(locations, start, finish, fuel, dp);
    }
};
