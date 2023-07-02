//problem: https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int len = requests.size();
        int ret = -1;
        for (int i = 0; i < (1 << len); ++i) {
            vector <int> cnt(n, 0);
            int bit = 0;
            for (int j = 0; j < len; ++j) {
                if ((i & (1 << j))) {
                    ++bit;
                    ++cnt[requests[j][0]];
                    --cnt[requests[j][1]];
                }
            }
            bool f = true;
            for (int a : cnt) {
                if (a) f = false;
            }
            if (f) ret = max(ret, bit);
        }
        return ret;
    }
};
