//problem: https://leetcode.com/problems/find-the-highest-altitude/

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ret = max(0, gain[0]);
        for (int i = 1; i < gain.size(); ++i) {
            gain[i] += gain[i - 1];
            ret = max(ret, gain[i]);
        }
        return ret;
    }
};
