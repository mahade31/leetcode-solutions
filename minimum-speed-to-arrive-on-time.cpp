//problem: https://leetcode.com/problems/minimum-speed-to-arrive-on-time/

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1, high = 1e7;
        int ret = -1;
        int len = dist.size();

        while (low <= high) {
            int mid = (low + high) / 2;
            int time = 0;
            for (int i = 0; i < len - 1; ++i) {
                time += (dist[i] + mid - 1) / mid;
            }
            double final_time = time + (double)dist[len - 1] / (double)mid;
            if (final_time <= hour) {
                ret = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ret;
    }
};
