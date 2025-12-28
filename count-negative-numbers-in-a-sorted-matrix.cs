//problem: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix

//Complexity: Time: O(n+m), Space: O(1)

//solution: 
public class Solution {
    public int CountNegatives(int[][] grid) {
        int n = grid.Count();
        int m = grid[0].Count();
        int j = m - 1;
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            while (j > 0 && grid[i][j - 1] < 0) {
                --j;
            }
            if (grid[i][j] < 0)
                ret += m - j;
        }

        return ret;
    }
}