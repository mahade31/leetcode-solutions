//problem: https://leetcode.com/problems/minimum-cost-to-make-array-equal/

//ternary search
class Solution {
private:
    long long calculate(vector<int>& nums, vector<int>& cost, int mid) {
        long long ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ret += 1LL * abs(mid - nums[i]) * cost[i];
        }
        return ret;
    }
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long ret = 1e18;
        int l = 0, r = 1e6;
        while (l <= r) {
            int mid1 = l + (r - l) / 3;
            int mid2 = r - (r - l) / 3;
            long long temp1 = calculate(nums, cost, mid1);
            long long temp2 = calculate(nums, cost, mid2);
            if (temp1 == temp2) {
                ret = temp1;
                l = mid1 + 1;
                r = mid2 - 1;
            }
            else if (temp1 < temp2) {
                ret = temp1;
                r = mid2 - 1;
            }
            else {
                ret = temp2;
                l = mid1 + 1;
            }
        }
        
        return ret;
    }
};

//binary search

class Solution {
private:
    long long calculate(vector<int>& nums, vector<int>& cost, int mid) {
        long long ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ret += 1LL * abs(mid - nums[i]) * cost[i];
        }
        return ret;
    }
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int l = 1, r = 1e6;
        while (l < r) {
            int mid = (l + r) / 2;
            long long temp1 = calculate(nums, cost, mid);
            long long temp2 = calculate(nums, cost, mid + 1);
            if (temp1 < temp2) r = mid;
            else l = mid + 1;
        }

        return calculate(nums, cost, l);
    }
};
