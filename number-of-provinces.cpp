//problem: https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = (int)isConnected.size();
        vector <int> edges[n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j and isConnected[i][j]) {
                    edges[i].push_back(j);
                }
            }
        }

        int ret = 0;
        bool visited[n];
        memset(visited, false, sizeof visited);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++ret;
                stack <int> st;
                st.push(i);
                visited[i] = true;
                while (!st.empty()) {
                    int a = st.top();
                    st.pop();
                    for (int b : edges[a]){
                        if (!visited[b]){
                            visited[b] = true;
                            st.push(b);
                        }
                    }
                }
            }
        }
        return ret;
    }
};
