//problem: https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/

class Solution {
public:
    long long sum(long long n) {
        return (n * (n + 1)) / 2;
    }
    long long sum_to(long long n, long long len) {
        if (n < len) {
            return sum(n) + len - n;
        }
        else {
            return sum(n) - sum(n - len);
        }
    }
    int maxValue(int n, int index, int maxSum) {
        int start = 1, end = 1e9;
        int ret = -1;
        int left = index + 1;
        int right = n - index;

        while (start <= end) {
            int mid = (start + end) / 2;
            long long tot = sum_to(mid, left) + sum_to(mid, right) - mid;
            if (tot <= maxSum) {
                ret = mid;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return ret;
    }
};
