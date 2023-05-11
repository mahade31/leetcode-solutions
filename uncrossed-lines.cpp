//problem: https://leetcode.com/problems/uncrossed-lines

class Solution {
public:
    int dp[501][501];
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2){
        if (dp[i][j] != -1)
            return dp[i][j];
        int mx = 0;
        for (int k = i; k < (int)nums1.size(); ++k){
            for (int l = j; l < (int)nums2.size(); ++l){
                if (nums1[k] == nums2[l]){
                    mx = max(mx, 1 + solve(k + 1, l + 1, nums1, nums2));
                }
            }
        }
        return dp[i][j] = mx;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof dp);
        int mx = 0;
        for (int i = 0; i < (int)nums1.size(); ++i){
            for (int j = 0; j < (int)nums2.size(); ++j){
                if (nums1[i] == nums2[j]){
                    mx = max(mx, 1 + solve(i + 1, j + 1, nums1, nums2));
                }
            }
        }
        return mx;
    }
};
