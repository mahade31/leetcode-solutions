//problem: https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/

class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector <vector<int>> vec;
        int len[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                vec.push_back({grid[i][j], i, j});
                len[i][j] = 1;
            }
        }
        sort (vec.begin(), vec.end());
        int dy[] = {1, 0, -1, 0};
        int dx[] = {0, -1, 0, 1};
        int ret = 0;
        int mod = 1e9 + 7;
        for (auto a : vec) {
            int x = a[0];
            int i = a[1];
            int j = a[2];
            for (int k = 0; k < 4; ++k) {
                int ii = i + dx[k];
                int jj = j + dy[k];
                if (ii >= 0 and ii < n and jj >= 0 and jj < m and x > grid[ii][jj]) {
                    len[i][j] += len[ii][jj];
                    len[i][j] %= mod;
                }
            }
            ret += len[i][j];
            ret %= mod;
        }
        return ret; 
    }
};
