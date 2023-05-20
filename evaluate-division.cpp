//problem: https://leetcode.com/problems/evaluate-division


class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map <string, int> mp;
        vector <int> edges[40];
        vector <double> cost[40];
        int temp = -1;
        
        for (int i = 0; i < equations.size(); ++i){
            string s = equations[i][0];
            string t = equations[i][1];
            double val = values[i];
            int u, v;
            if (mp.count(s))
                u = mp[s];
            else {
                u = ++temp;
                mp[s] = u;
            }
            if (mp.count(t))
                v = mp[t];
            else {
                v = ++temp;
                mp[t] = v;
            }
            edges[u].push_back(v);
            cost[u].push_back(val);
            edges[v].push_back(u);
            cost[v].push_back(1.0/val);
        }

        vector <double> ret;
        for (auto qr : queries) {
            bool vis[40];
            memset(vis, 0, sizeof vis);
            double ans[40];
            for (int i = 0; i < 40; ++i)
                ans[i] = 1.0;
            queue <int> q;
            if (mp.count(qr[0])) {
                q.push(mp[qr[0]]);
                vis[mp[qr[0]]] = true;
                while (!q.empty()){
                    int u = q.front();
                    q.pop();
                    for (int i = 0; i < edges[u].size(); ++i) {
                        int v = edges[u][i];
                        if (!vis[v]){
                            ans[v] = ans[u] * cost[u][i];
                            q.push(v);
                            vis[v] = true;
                        }
                    }
                }
            }
            if (mp.count(qr[1]) and vis[mp[qr[1]]])
                ret.push_back(ans[mp[qr[1]]]);
            else
                ret.push_back(-1);
        }

        return ret;
    }
};
