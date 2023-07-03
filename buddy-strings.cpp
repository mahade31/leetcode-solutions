//problem: https://leetcode.com/problems/buddy-strings

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;

        int len = s.size();
        int a = -1, b = -1, cnt = 0;
        set <char> st;

        for (int i = 0; i < len; ++i) {
            st.insert(s[i]);
            if (s[i] != goal[i]) {
                if (a == -1) a = i;
                else b = i;
                ++cnt;
            }
        }

        if (cnt == 2) {
            swap(s[a], s[b]);
            return s == goal;
        }
        else if (cnt == 0) {
            return st.size() != s.size();
        }
        return false;
    }
};
