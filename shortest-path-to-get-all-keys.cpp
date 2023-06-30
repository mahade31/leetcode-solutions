//problem: https://leetcode.com/problems/shortest-path-to-get-all-keys/

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int sr = -1, sc = -1;
        int all_keys = 0;
        int keys_count = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '@') {
                    sr = i;
                    sc = j;
                }
                else if (grid[i][j] >= 'a' and grid[i][j] <= 'f') {
                    all_keys += (1 << (grid[i][j] - 'a'));
                    ++keys_count;
                }
            }
        }

        int visited[n][m][1 << keys_count];
        memset(visited, -1, sizeof visited);

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        queue <vector<int>> q;
        q.push({sr, sc, 0});
        visited[sr][sc][0] = 0;

        while (!q.empty()) {
            auto a = q.front();
            int x = a[0];
            int y = a[1];
            int keys = a[2];
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int xx = x + dx[i];
                int yy = y + dy[i];

                if (xx >= 0 and yy >= 0 and xx < n and yy < m) {
                    if ((grid[xx][yy] == '.' or grid[xx][yy] == '@') and visited[xx][yy][keys] == -1) {
                        visited[xx][yy][keys] = visited[x][y][keys] + 1;
                        q.push({xx, yy, keys});
                    }
                    else if (grid[xx][yy] >= 'a' and grid[xx][yy] <= 'f') {
                        if (visited[xx][yy][keys | (1 << (grid[xx][yy] - 'a'))] == -1) {
                            visited[xx][yy][keys | (1 << (grid[xx][yy] - 'a'))] = visited[x][y][keys] + 1;
                            q.push({xx, yy, keys | (1 << (grid[xx][yy] - 'a'))});
                        }
                    }
                    else if (grid[xx][yy] >= 'A' and grid[xx][yy] <= 'F' and (keys & (1 << (grid[xx][yy] - 'A')))) {
                        if (visited[xx][yy][keys] == -1) {
                            visited[xx][yy][keys] = visited[x][y][keys] + 1;
                            q.push({xx, yy, keys});
                        }
                    }
                }
            }
        }
        int ret = 1e9;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (visited[i][j][all_keys] != -1) {
                    ret = min(ret, visited[i][j][all_keys]);
                }
            }
        }

        return (ret == 1e9 ? -1 : ret);
    }
};
