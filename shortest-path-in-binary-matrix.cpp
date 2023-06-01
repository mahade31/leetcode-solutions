//problem: https://leetcode.com/problems/shortest-path-in-binary-matrix/

class Solution {
public:
    bool is_valid(int x, int y, int n, int m) {
        if (x < 0 or y < 0 or x >= n or y >= m)
            return false;
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int visited[n][m];
        memset(visited, -1, sizeof visited);

        if (!grid[0][0]) {
            queue <int> q;
            q.push(0);
            q.push(0);
            visited[0][0] = 1;
            int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
            int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                int y = q.front();
                q.pop();
                for (int i = 0; i < 8; ++i) {
                    int xx = x + dx[i];
                    int yy = y + dy[i];

                    if (is_valid(xx, yy, n, m) and visited[xx][yy] == -1 and !grid[xx][yy]) {
                        visited[xx][yy] = visited[x][y] + 1;
                        q.push(xx);
                        q.push(yy);
                    }
                }
            }
        }
        return visited[n - 1][m - 1];
    }
};
