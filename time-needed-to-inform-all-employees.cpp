//problem: https://leetcode.com/problems/time-needed-to-inform-all-employees/

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector <int> edges[n];
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1) {
                edges[manager[i]].push_back(i);
            }
        }

        queue <int> q;
        q.push(headID);
        int time[n];
        memset(time, 0, sizeof time);
        while (!q.empty()) {
            int a = q.front();
            q.pop();
            for (int b : edges[a]) {
                time[b] = time[a] + informTime[a];
                q.push(b);
            }
        }
        int ret = 0;
        for (int i = 0; i < n; ++i)
            ret = max(ret, time[i]);

        return ret;
    }
};
