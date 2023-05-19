//problem: https://leetcode.com/problems/is-graph-bipartite
/*

This problem can be solved if we find that if the nodes of the graph can be colored using two colors such that not adjacent nodes has the same color.

If we can color a graph using this constraints, then we divide the nodes in two sets. One color in one set and other color in another set. 

So we start with a node by coloring it with any color and try to color the neighboring nodes with different color. We keep trying to do these for every node. If we fail then the graph is not bipartite. To implement this we can modify BFS a bit.

*/
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
