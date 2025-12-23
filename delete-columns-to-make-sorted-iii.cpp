//problem: https://leetcode.com/problems/delete-columns-to-make-sorted-iii

//time: O(n*m^2), space: O(m)


//solution
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs[0].size();
        int n = strs.size();
        vector<int> vec(m, 1);
        int mx = 1;
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < i; ++j) {
                bool allOk = true;
                for (int k = 0; k < n; ++k) {
                    if (strs[k][i] < strs[k][j]) {
                        allOk = false;
                        break;
                    }
                }
                if (allOk) {
                    vec[i] = max(vec[i], vec[j] + 1);
                }
            }
            mx = max(mx, vec[i]);
        }

        return m - mx;
    }
};