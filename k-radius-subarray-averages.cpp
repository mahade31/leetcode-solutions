//problem: https://leetcode.com/problems/k-radius-subarray-averages/

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector <int> ret;
        int n = nums.size();
        for (int i = 0; i < min(n, k); ++i) ret.push_back(-1);
        if (n > 2 * k) {
            long long sum = 0;
            for (int i = 0; i <= 2 * k; ++i) sum += nums[i];
            int l = 0, r = 2 * k + 1;
            ret.push_back(sum / (2 * k + 1));
            for (int i = r; i < n; ++i) {
                sum -= nums[l++]; 
                sum += nums[i];
                ret.push_back(sum / (2 * k + 1));
            }
        }
        
        for (int i = 0; i < min(k, n - k); ++i) ret.push_back(-1);
        return ret;
    }
};
