//problem: https://leetcode.com/problems/buddy-strings

//O(n*log(n))
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

//O(n)

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;

        int len = s.size();
        int a = -1, b = -1, cnt = 0;
        int st[26];
        memset(st, 0, sizeof st);

        for (int i = 0; i < len; ++i) {
            ++st[s[i] - 'a'];
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
            for (int i = 0; i < 26; ++i) {
                if (st[i] >= 2) return true;
            }
        }
        return false;
    }
};
