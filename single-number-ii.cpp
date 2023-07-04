//problem: https://leetcode.com/problems/single-number-ii/


//O(n*log(n)), O(n*log(n))
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map <int, int> mp;
        for (int a : nums) ++mp[a];

        for (auto a : mp) if (a.second == 1) return a.first;
        return -1;
    }
};
