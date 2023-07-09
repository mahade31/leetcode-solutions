//problem: https://leetcode.com/problems/substring-with-largest-variance/

class Solution {
public:
    int largestVariance(string s) {
        int cnt[26];
        memset (cnt, 0, sizeof cnt);

        for (char c : s) ++cnt[c - 'a'];

        int ret = 0;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (i == j or cnt[i] == 0 or cnt[j] == 0) continue;
                int a = 0, b = 0;
                int rest = cnt[j];
                for (char c : s) {
                    if (c == i + 'a') ++a;
                    if (c == j + 'a') ++b, --rest;
                    if (b) ret = max(ret, a - b);
                    if (a < b and rest > 0) {
                        a = 0;
                        b = 0;
                    }
                }
            }
        }
        return ret;
    }
};
