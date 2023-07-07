//problem: https://leetcode.com/problems/maximize-the-confusion-of-an-exam/

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int len = answerKey.length();
        int prefix_sum[len];
        memset(prefix_sum, 0, sizeof prefix_sum);

        for (int i = 0; i < len; ++i) {
            prefix_sum[i] = answerKey[i] == 'T';
            if (i) prefix_sum[i] += prefix_sum[i - 1];
        }
        
        int ret = -1;
        for (int i = 0; i < len; ++i) {
            int start = i, end = len - 1;
            while (start <= end) {
                int mid = (start + end) / 2;
                int t = prefix_sum[mid] - (i ? prefix_sum[i - 1] : 0);
                int f = mid - i + 1 - t;
                if (t <= k or f <= k) {
                    ret = max(ret, mid - i + 1);
                    start = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
        }

        return ret;
    }
};
