//problem: https://leetcode.com/problems/shortest-bridge

//solved using optimized BFS
class Solution {
public:
    bool is_valid(int x, int y, int n){
        if (x < 0 or y < 0 or x >= n or y >= n) return false;
        return true;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        int n = grid.size();
        int x, y;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j]){
                    x = i;
                    y = j;
                }
            }
        }
        vector <int> vec;
        queue <int> q;
        int vis[n][n];
        memset(vis, 0, sizeof vis);
        vis[x][y] = true;
        q.push(x);
        q.push(y);
        vec.push_back(x);
        vec.push_back(y);
        while (!q.empty()){
            x = q.front();
            q.pop();
            y = q.front();
            grid[x][y] = 2;
            q.pop();
            for (int i = 0; i < 4; ++i){
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (is_valid(xx, yy, n) and !vis[xx][yy] and grid[xx][yy]){
                    vis[xx][yy] = true;
                    q.push(xx);
                    q.push(yy);
                    vec.push_back(xx);
                    vec.push_back(yy);
                }
            }
        }

        int ret = 1e9;
        memset(vis, 0, sizeof vis);
        for (int i = 1; i < vec.size(); i += 2){
            queue<int> temp;
            x = vec[i - 1];
            y = vec[i];
            temp.push(x);
            temp.push(y);
            vis[x][y] = 1;
            q.push(x);
            q.push(y);

            while (!q.empty()){
                x = q.front();
                q.pop();
                y = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i){
                    int xx = x + dx[i];
                    int yy = y + dy[i];
                    if (is_valid(xx, yy, n) and !vis[xx][yy] and !grid[xx][yy]){
                        vis[xx][yy] = vis[x][y] + 1;
                        q.push(xx);
                        q.push(yy);
                        temp.push(xx);
                        temp.push(yy);
                    }
                    else if (is_valid(xx, yy, n) and grid[xx][yy] == 1){
                        ret = min(ret, vis[x][y] - 1);
                    }
                }
            }

            while (!temp.empty()){
                x = temp.front();
                temp.pop();
                y = temp.front();
                temp.pop();
                vis[x][y] = 0;
            }
        }
        return ret;
    }
};


//solved using multisource BFS

class Solution {
public:
    bool is_valid(int x, int y, int n){
        if (x < 0 or y < 0 or x >= n or y >= n) return false;
        return true;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        int n = grid.size();
        int x, y;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j]){
                    x = i;
                    y = j;
                }
            }
        }
        queue <int> qq;
        queue <int> q;
        int vis[n][n];
        memset(vis, 0, sizeof vis);
        vis[x][y] = true;
        q.push(x);
        q.push(y);
        qq.push(x);
        qq.push(y);
        while (!q.empty()){
            x = q.front();
            q.pop();
            y = q.front();
            grid[x][y] = 2;
            q.pop();
            for (int i = 0; i < 4; ++i){
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (is_valid(xx, yy, n) and !vis[xx][yy] and grid[xx][yy]){
                    vis[xx][yy] = true;
                    q.push(xx);
                    q.push(yy);
                    qq.push(xx);
                    qq.push(yy);
                }
            }
        }

        int ret = 1e9;
        memset(vis, 0, sizeof vis);
        while (!qq.empty()){
            x = qq.front();
            qq.pop();
            y = qq.front();
            qq.pop();
            for (int i = 0; i < 4; ++i){
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (is_valid(xx, yy, n) and !vis[xx][yy] and !grid[xx][yy]){
                    vis[xx][yy] = vis[x][y] + 1;
                    qq.push(xx);
                    qq.push(yy);
                }
                else if (is_valid(xx, yy, n) and grid[xx][yy] == 1){
                    ret = min(ret, vis[x][y]);
                }
            }
        }
        
        return ret;
    }
};
