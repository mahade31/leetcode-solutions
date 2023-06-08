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
