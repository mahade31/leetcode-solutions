//problem: https://leetcode.com/problems/non-overlapping-intervals/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int cnt = 1;
        int last = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= intervals[last][1]) {
                ++cnt;
                last = i;
            }
            else if (intervals[i][1] <= intervals[last][1]) {
                last = i;
            }
        }

        return intervals.size() - cnt;
    }
};
