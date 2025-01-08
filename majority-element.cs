/*
Problem: https://leetcode.com/problems/majority-element/

Solution:
	Time: O(n)
	Space: O(1)
*/

public class Solution {
    public int MajorityElement(int[] nums) {
        int majorNum = nums[0];
        int majorCount = 1;

        for (int i = 1; i < nums.Count(); ++i) {
            if (nums[i] == majorNum) {
                ++majorCount;
            }
            else if (majorCount == 1) {
                majorNum = nums[i];
            }
            else {
                --majorCount;
            }
        }

        return majorNum;
    }
}