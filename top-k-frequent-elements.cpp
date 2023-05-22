//problem: https://leetcode.com/problems/top-k-frequent-elements


//solution 1: O(n log n) where n = 20000(range of given numbers)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int cnt[20004];
        memset(cnt, 0, sizeof cnt);
        for (int a : nums) {
            ++cnt[a + 10000];
        }
        vector <pair<int, int>> vec;
        for (int i = 0; i <= 20000; ++i){
            vec.push_back({-cnt[i], i - 10000});
        }
        sort (vec.begin(), vec.end());
        vector <int> ret;
        for (int i = 0; i < k; ++i)
            ret.push_back(vec[i].second);
        return ret;
    }
};

//solution 2: O(n log n) where n = length of the list.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map <int, int> cnt;
        for (int a : nums) {
            ++cnt[a];
        }
        vector <pair<int, int>> vec;
        for (auto it : cnt){
            vec.push_back({it.second, it.first});
        }
        sort (vec.rbegin(), vec.rend());
        vector <int> ret;
        for (int i = 0; i < k; ++i)
            ret.push_back(vec[i].second);
        return ret;
    }
};
