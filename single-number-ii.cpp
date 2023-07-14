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

//O(n) using bit manipulation

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one_time = 0, two_time = 0;
        for (int a : nums) {
            one_time ^= a & ~two_time;
            two_time ^= a & ~one_time;
        }
        return one_time;
    }
};
