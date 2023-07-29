//problem: https://leetcode.com/problems/soup-servings/

//without optimization
class Solution {
private:
    vector <vector<int>> moves{{100, 0}, {75, 25}, {50, 50}, {25, 75}};

    double solve(int i, int j, vector <vector<double>>& dp) {
        if (i >= 5000) return 1;
        if (i == 0 and j == 0) return .5;
        if (i == 0 and j > 0) return 1;
        if (j == 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        double res = 0;
        for (auto a : moves) {
            res += .25 * solve(max(0, i - a[0]), max(0, j - a[1]), dp);
        }

        return dp[i][j] = res;
    }
public:
    double soupServings(int n) {
        vector <vector<double>> dp(min(n + 1, 5001), vector<double>(min(n + 1, 5001), -1));
        return solve(n, n, dp);
    }
};


//optimized
class Solution {
private:
    vector <vector<int>> moves{{4, 0}, {3, 1}, {2, 2}, {1, 3}};

    double solve(int i, int j, vector <vector<double>>& dp) {
        if (i >= 200) return 1;
        if (i == 0 and j == 0) return .5;
        if (i == 0 and j > 0) return 1;
        if (j == 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        double res = 0;
        for (auto a : moves) {
            res += .25 * solve(max(0, i - a[0]), max(0, j - a[1]), dp);
        }

        return dp[i][j] = res;
    }
public:
    double soupServings(int n) {
        vector <vector<double>> dp(201, vector<double> (201, -1));
        return solve((n + 24) / 25, (n + 24) / 25, dp);
    }
};
