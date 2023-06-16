//problem: https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/

class Solution {
private:
    int comb[1003][1003];
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        memset(comb, 0, sizeof comb);
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0 or i == j) comb[i][j] = 1;
                else comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % 1000000007;
            }
        }
        return (solve(nums) - 1) % 1000000007;
    }
    long long solve(vector <int> nums) {
        int n = nums.size();
        if (n <= 1) return 1;

        vector <int> left, right;

        for (int a : nums) {
            if (a < nums[0]) left.push_back(a);
            else if (a > nums[0]) right.push_back(a);
        }

        long long left_count = solve(left);
        long long right_count = solve(right);

        return (((left_count * right_count) % 1000000007) * comb[n - 1][left.size()]) % 1000000007;
    }
};
