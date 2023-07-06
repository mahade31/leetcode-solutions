//problem: https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0;
        int len = nums.size();
        int sum = 0;
        int ret = 1e9;
        while (j < len) {
            while (j < len and sum < target) {
                sum += nums[j];
                ++j;
            }
            if (sum >= target) {
                ret = min(ret, j - i);
            }
            while (i < j and sum >= target) {
                sum -= nums[i];
                ++i;
                if (sum >= target) {
                    ret = min(ret, j - i);
                }
            }
        }
        return (ret == 1e9 ? 0 : ret);
    }
};
