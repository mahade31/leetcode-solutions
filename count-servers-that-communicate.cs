/*
Problem: https://leetcode.com/problems/count-servers-that-communicate

Solution:
	Time: O(n*m)
	Space: O(n+m)
*/

public class Solution {
    public int CountServers(int[][] grid) {
        int totalRow = grid.Count();
        int totalColumn = grid[0].Count();

        int[] rowCount = new int[totalRow];
        int[] columnCount = new int[totalColumn];

        for (int i = 0; i < totalRow; ++i) {
            for (int j = 0; j < totalColumn; ++j) {
                if (grid[i][j] > 0) {
                    ++rowCount[i];
                    ++columnCount[j];
                }
            }
        }

        int ret = 0;

        for (int i = 0; i < totalRow; ++i) {
            for (int j = 0; j < totalColumn; ++j) {
                if (grid[i][j] > 0 && (rowCount[i] > 1 || columnCount[j] > 1)) {
                    ++ret;
                }
            }
        }

        return ret;
    }
}