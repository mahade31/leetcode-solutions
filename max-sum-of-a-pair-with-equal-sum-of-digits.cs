/*
Problem: https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/

Solution:
	Time: O(n * log10(n))
	Space: O(log10(n))
*/


public class Solution {
    public int MaximumSum(int[] nums) {
        int[] maxNum = new int[100];
        Array.Fill(maxNum, -1);
        int ret = -1;
        for (int i = 0; i < nums.Count(); ++i) {
            int digitSum = GetDigitSum(nums[i]);
            if (maxNum[digitSum] != -1) {
                ret = Math.Max(ret, maxNum[digitSum] + nums[i]);
            }
            maxNum[digitSum] = Math.Max(maxNum[digitSum], nums[i]);
        }
        return ret;
    }
    public int GetDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
}
