//problem: https://leetcode.com/problems/is-graph-bipartite

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int visited[n];
        memset(visited, 0, sizeof visited);
        for (int i = 0; i < n; ++i){
            if (!visited[i]){
                queue <int> q;
                q.push(i);
                visited[i] = 1;
                while (!q.empty()){
                    int u = q.front();
                    q.pop();
                    for (int v : graph[u]){
                        if (!visited[v]){
                            visited[v] = visited[u] + 1;
                            q.push(v);
                        }
                        else if ((visited[v] & 1) == (visited[u] & 1))
                            return false;
                    }
                }
            }
        }
        return true;
    }
};
