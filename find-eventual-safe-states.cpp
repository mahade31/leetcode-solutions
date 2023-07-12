//problem: https://leetcode.com/problems/find-eventual-safe-states/

class Solution {
private:
    vector <int> isSafe;
    vector <bool> vis;
    int dfs(int u, vector<vector<int>>& graph) {
        if (graph[u].size() == 0) return 1;
        if (isSafe[u] != -1) return isSafe[u];
        if (vis[u]) return 0;
        vis[u] = true;
        bool f = true;
        for (int v : graph[u]) {
            f = f and dfs(v, graph);
        }
        return isSafe[u] = f;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        for (int i = 0; i < n; ++i) isSafe.push_back(-1), vis.push_back(false);
        vector <int> ret;
        for (int i = 0; i < n; ++i) {
            if (isSafe[i] == -1) {
                isSafe[i] = dfs(i, graph);
            }
            if (isSafe[i]) ret.push_back(i);
        }
        return ret;
    }
};

//topological sort

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector <int> ret;
        
        vector <vector<int>> rev_graph(n, vector<int>());
        vector <int> out_degree(n);
        for (int u = 0; u < n; ++u) {
            for (int v : graph[u]) {
                rev_graph[v].push_back(u);
                ++out_degree[u];
            }
        }

        queue <int> q;
        for (int i = 0; i < n; ++i) {
            if (out_degree[i] == 0) {
                q.push(i);
            }
        }

        vector <int> is_safe(n);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            is_safe[u] = true;
            for (int v : rev_graph[u]) {
                --out_degree[v];
                if (out_degree[v] == 0) {
                    q.push(v);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (is_safe[i]) ret.push_back(i);
        }

        return ret;
    }
};
