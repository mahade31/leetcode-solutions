//problem: https://leetcode.com/problems/check-if-it-is-a-straight-line/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        set <pair<int, int>> st;
        int n = coordinates.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int x = abs(coordinates[i][0] - coordinates[j][0]);
                int y = abs(coordinates[i][1] - coordinates[j][1]);
                int gcd = __gcd(x, y);
                x /= gcd;
                y /= gcd;
                st.insert({x, y});
                if (st.size() == 2)
                    return false;
            }
        }
        return true;
    }
};
