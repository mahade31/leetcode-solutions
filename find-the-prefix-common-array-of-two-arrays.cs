/*
Problem: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/

Solution:
	Time: O(n^3)
	Space: O(n)
*/

public class Solution {
    public int[] FindThePrefixCommonArray(int[] A, int[] B) {
        int len = A.Count();
        int[] ret = new int[len];
        
        for (int i = 0; i < len; ++i) {
            int ans = 0;
            for (int k = i; k >= 0; --k) {
                for (int j = 0; j <= i; ++j) {
                    if (B[k] == A[j]) {
                        ++ans;
                        break;
                    }
                }
            }
            
            ret[i] = ans;
        }

        return ret;
    }
}