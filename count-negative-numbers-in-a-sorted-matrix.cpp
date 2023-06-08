//problem: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

//solution 1: O(m*n)

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ret = 0;
        for (auto v : grid) {
            for (int a : v) {
                if (a < 0) ++ret;
            }
        }
        return ret;
    }
};

//solution 2: O(m + n)

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ret = 0;
        int n = grid.size();
        int m = grid[0].size();
        int i = 0, j = m - 1;
        while (j >= 0) {
            while (i < n and grid[i][j] >= 0) {
                ++i;
            }
            ret += n - i;
            --j;
        }
        return  ret;
    }
};
