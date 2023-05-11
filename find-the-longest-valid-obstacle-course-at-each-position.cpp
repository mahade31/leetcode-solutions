//problem: https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector <int> ret, lis;
        for (int a : obstacles){
            int pos = upper_bound(lis.begin(), lis.end(), a) - lis.begin();
            if (pos == lis.size())
                lis.push_back(a);
            else
                lis[pos] = a;
            ret.push_back(pos + 1);
        }
        return ret;
    }
};
