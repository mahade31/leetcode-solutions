//problem: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len = nums.size();
        vector <int> zero_pos;
        for (int i = 0; i < len; ++i) {
           if (!nums[i]) zero_pos.push_back(i); 
        }

        if (zero_pos.size() == 0) return len - 1;

        int ret = -1;
        for (int i = 0; i < len; ++i) {
            if (!nums[i]) {
                int pos = lower_bound(zero_pos.begin(), zero_pos.end(), i) - zero_pos.begin();
                int start = (pos - 1) >= 0 ? zero_pos[pos - 1] : -1;
                int end = (pos + 1) < zero_pos.size() ? zero_pos[pos + 1] : len;
                ret = max(ret, end - start - 2);
            }
        }
        return ret;
    }
};
