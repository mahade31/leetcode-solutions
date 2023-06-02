//problem: https://leetcode.com/problems/detonate-the-maximum-bombs/

class Solution {
public:
    long long square(long long x){
        return x*x;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            bool visited[n];
            memset (visited, false, sizeof visited);
            int cnt = 1;
            queue <int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                int a = q.front();
                q.pop();
                for (int j = 0; j < n; ++j) {
                    if (!visited[j]) {
                        long long dist = square(bombs[a][0] - bombs[j][0]) + square(bombs[a][1] - bombs[j][1]);
                        if (dist <= square(bombs[a][2])) {
                            q.push(j);
                            ++cnt;
                            visited[j] = true;
                        }
                    }
                }
            }
            ret = max(ret, cnt);
        }
        return ret;
    }
};
