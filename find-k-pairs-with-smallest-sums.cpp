//problem: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector <vector<int>> ret;
        int n = nums1.size(), m = nums2.size();
        set <pair<int, pair<int, int>>> st;
        st.insert({{nums1[0] + nums2[0]}, {0, 0}});
        set <pair<int, int>> visited;
        while (k-- and !st.empty()) {
            auto a = *st.begin();
            st.erase(st.begin());

            int i = a.second.first;
            int j = a.second.second;

            ret.push_back({nums1[i], nums2[j]});

            if (i + 1 < n and visited.find({i + 1, j}) == visited.end()) {
                st.insert({nums1[i + 1] + nums2[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }
            
            if (j + 1 < m and visited.find({i, j + 1}) == visited.end()) {
                st.insert({nums1[i] + nums2[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }
            
        }
        return ret;
    }
};
