//problem: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        int in_degree[n];
        memset (in_degree, 0, sizeof in_degree);
        for (auto p : edges){
            ++in_degree[p[1]];
        }
        vector <int> ret;
        for (int i = 0; i < n; ++i) {
            if (!in_degree[i])
                ret.push_back(i);
        }
        return ret;
    }
};
