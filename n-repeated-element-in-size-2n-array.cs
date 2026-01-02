//problem: https://leetcode.com/problems/n-repeated-element-in-size-2n-array

//time complexity: O(n)
//space complexity: O(1)

//solution:
public class Solution {
    public int RepeatedNTimes(int[] nums) {
        int n = nums.Count();
        for (int i = 0; i < Math.Min(n, n - 3); ++i) {
            for (int j = i; j < Math.Min(n, i + 4); ++j) {
                for (int k = j + 1; k < Math.Min(n, i + 4); ++k) {
                    if (nums[j] == nums[k]) return nums[j];
                }
            }
        }
        return -1;
    }
}