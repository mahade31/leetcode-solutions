//problem: https://leetcode.com/problems/last-day-where-you-can-still-cross/

class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>& grid, int n, int m) {
        if (i < 0 or j < 0 or i >= n or j >= m) return;
        if (grid[i][j]) return;
        grid[i][j] = 2;
        dfs(i + 1, j, grid, n, m);
        dfs(i - 1, j, grid, n, m);
        dfs(i, j + 1, grid, n, m);
        dfs(i, j - 1, grid, n, m);
    }

public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int i = 0, j = cells.size() - 1;
        int ret = -1;
        while (i <= j) {
            int mid = (i + j) / 2;
            vector <vector<int>> grid(row, vector<int> (col, 0));
            for (int k = 0; k <= mid; ++k) grid[cells[k][0] - 1][cells[k][1] - 1] = 1;

            for (int k = 0; k < col; ++k) {
                if (grid[0][k] != 1) dfs(0, k, grid, row, col);
            }

            bool possible = false;
            for (int k = 0; k < col; ++k) {
                if (grid[row - 1][k] == 2) {
                    possible = true;
                    break;
                }
            }

            if (possible) {
                ret = mid + 1;
                i = mid + 1;
            }
            else j = mid - 1;
        }
        return ret;
    }
};
