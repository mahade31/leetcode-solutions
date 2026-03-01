//problem: https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers


//time: O(n), space: O(1)

//solution

class Solution {
public:
    int minPartitions(string n) {
        int ret = -1;
        for (char c : n) {
            ret = max(ret, c - '0');
        }
        return ret;
    }
};