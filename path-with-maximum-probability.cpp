//problem: https://leetcode.com/problems/path-with-maximum-probability/

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector <vector<int>> adj(n, vector <int> (0));
        vector <vector<double>> cost(n, vector <double> (0));
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            double c = succProb[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
            cost[u].push_back(c);
            cost[v].push_back(c);
        }

        double res[n];
        for (int i = 0; i < n; ++i) res[i] = 0;
        queue <int> q;
        q.push(start);
        res[start] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int i = 0; i < adj[u].size(); ++i) {
                int v = adj[u][i];
                double c = cost[u][i];

                if (res[u] * c > res[v]) {
                    res[v] = res[u] * c;
                    q.push(v);
                }
            }
        }
    
        return res[end];
    }
};
