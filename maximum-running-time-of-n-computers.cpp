//problem: https://leetcode.com/problems/maximum-running-time-of-n-computers/

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long low = 1, high = 1e14;

        while (low < high) {
            long long mid = (low + high + 1) / 2;
            long long sum = 0;
            for (int a : batteries) sum += min(1LL*a, mid);
            if (sum >= n*mid) low = mid;
            else high = mid - 1;
        }

        return low;
    }
};
