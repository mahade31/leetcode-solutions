//problem: https://leetcode.com/problems/fair-distribution-of-cookies/

class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int ret = 1e9;
        int len = cookies.size();
        sort(cookies.begin(), cookies.end());

        do {
            for (int i = 1; i < (1 << len); ++i) {
                if (__builtin_popcount(i) == (k - 1)) {
                    int sum = 0;
                    int mx = -1;
                    for (int j = 0; j < len; ++j) {
                        sum += cookies[j];
                        if ((i & (1 << j))) {
                            mx = max(mx, sum);
                            sum = 0;
                        }
                    }
                    mx = max(mx, sum);
                    ret = min(ret, mx);
                }
            }
        } while (next_permutation(cookies.begin(), cookies.end()));

        return  ret;
    }
};
