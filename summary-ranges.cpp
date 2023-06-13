//problem: https://leetcode.com/problems/summary-ranges/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i = 0, j = 0;
        int n = nums.size();
        vector <string> ret;
        while (j < n) {
            while (j + 1 < n and nums[j] + 1 == nums[j + 1])
                ++j;
            string s = to_string(nums[i]);
            string t = to_string(nums[j]);
            if (i == j)
                ret.push_back(s);
            else
                ret.push_back(s + "->" + t);
            ++j;
            i = j;
        }
        return ret;
    }
};
