//problem: https://leetcode.com/problems/maximum-score-of-a-split

//time complexity: O(n)
//space complexity: O(1)

//solution:
public class Solution {
    public long MaximumScore(int[] nums) {
        long sum = 0;
        foreach (var num in nums) {
            sum += num;
        }

        long min = (long)1e10;
        long ret = (long)-1e15;
        int n = nums.Count();

        for (int i = n - 2; i >= 0; --i) {
            min = Math.Min(min, nums[i + 1]);
            sum -= nums[i + 1];

            ret = Math.Max(ret, sum - min);
        }

        return ret;
    }
}