//problem: https://leetcode.com/problems/make-array-strictly-increasing/

//using map
class Solution {
private:
    map <pair<int, int>, int> dp;
public:
    int solve(int i, int prev, vector<int>& arr1, vector<int>& arr2) {
        if (i == arr1.size()) {
            return 0;
        }
        if (dp.count({i, prev})) return dp[{i, prev}];
        int way1 = 1e9;
        int way2 = 1e9;
        int ind = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
        if (ind < arr2.size()) {
            way2 = 1 + solve(i + 1, arr2[ind], arr1, arr2);
        }
        if (arr1[i] > prev)
            way1 = solve(i + 1, arr1[i], arr1, arr2);
        return dp[{i, prev}] = min(way1, way2);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        int ret = solve(0, -1, arr1, arr2);
        return (ret == 1e9 ? -1 : ret);
    }
};

