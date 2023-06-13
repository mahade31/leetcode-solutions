//problem: https://leetcode.com/problems/equal-row-and-column-pairs/

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map <vector<int>, int> mp;
        for (auto a : grid)
            ++mp[a];
        int n = grid.size();
        int m = grid[0].size();
        int ret = 0;
        for (int j = 0; j < m; ++j){
            vector <int> vec;
            for (int i = 0; i < n; ++i) {
                vec.push_back(grid[i][j]);
            }
            ret += mp[vec];
        }
        return ret;
    }
};
