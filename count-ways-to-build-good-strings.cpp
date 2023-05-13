//problem: https://leetcode.com/problems/count-ways-to-build-good-strings

/*
here starting with an empty string, we have two choices
i) to append '0' zero times
ii) to append '1' one times

Also, it doesn't matter what the result string is. Only the length matters, if we only follow those two choices. 
After choosing option i or ii, if the length becomes good it results in a good string.

And adding memoization optimizes the runtime to O(high)
*/


class Solution {
public:
    bool is_good(int len, int low, int high){
        return (len >= low and len <= high);
    }
    int solve(int len, int low, int high, int zero, int one, int dp[]){
        if (len > high)
            return 0;
        if (dp[len] != -1)
            return dp[len];
        int ret = is_good(len + one, low, high) + solve(len + one, low, high, zero, one, dp) + 
            is_good(len + zero, low, high) + solve(len + zero, low, high, zero, one, dp);
        return dp[len] = ret % 1000000007;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        int dp[high + 1];
        memset(dp, -1, sizeof dp);
        return solve(0, low, high, zero, one, dp);
    }
};
