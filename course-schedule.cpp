//problem: https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector <int> in_degree(numCourses, 0);
        vector <vector<int>> edges(numCourses, vector<int>());

        for (auto p : prerequisites) {
            int a = p[0];
            int b = p[1];
            ++in_degree[a];
            edges[b].push_back(a);
        }

        queue <int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }

        int cnt = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ++cnt;
            for (int v : edges[u]) {
                --in_degree[v];
                if (in_degree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return cnt == numCourses;
    }
};
