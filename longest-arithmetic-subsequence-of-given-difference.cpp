//problem: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        vector <int> mp(40004, 0);
        int ret = 0;
        for (int a : arr) {
            mp[a + 20000] = mp[a - difference + 20000] + 1;
            ret = max(ret, mp[a + 20000]);
        }
        return ret;
    }
};
