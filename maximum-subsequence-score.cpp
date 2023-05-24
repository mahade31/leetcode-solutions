//problem: https://leetcode.com/problems/maximum-subsequence-score

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector <pair<int, int>> vec;
        for (int i = 0; i < nums2.size(); ++i) {
            vec.push_back({nums2[i], i});
        }

        sort(vec.rbegin(), vec.rend());
        multiset <int> st;
        long long ret = 0;
        long long sum = 0;
        for (int i = 0; i < k; ++i){
            st.insert(nums1[vec[i].second]);
            sum += nums1[vec[i].second];
        }
        ret = 1LL * sum * vec[k - 1].first;

        for (int i = k; i < n; ++i) {
            int op1 = *st.begin();
            st.erase(st.begin());
            sum -= op1;
            int op2 = nums1[vec[i].second];
            sum += op2;
            ret = max(ret, 1LL * sum * vec[i].first);
            if (op1 > op2){
                sum -= op2;
                sum += op1;
                st.insert(op1);
            } else {
                st.insert(op2);
            }
        }

        return ret;
    }
};
