//problem: https://leetcode.com/problems/total-cost-to-hire-k-workers/

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int len = costs.size();
        long long ret = 0;
        int i = 0, j = len - 1;
        set <pair<int, int>> front, back;
        while (i < candidates) {
            front.insert({costs[i], i});
            ++i;
        }
        while (j >= i and j >= len - candidates) {
            back.insert({costs[j], -j});
            --j;
        }

        while (k--) {
            auto a = make_pair(1e9, -1);
            auto b = make_pair(1e9, -1);
            if (!front.empty())
                a = *front.begin();
            if (!back.empty())
                b = *back.begin();

            if (a.first <= b.first) {
                ret += a.first;
                front.erase(front.begin());
                if (i <= j) {
                    front.insert({costs[i], i});
                    ++i;
                }
            }
            else {
                ret += b.first;
                back.erase(back.begin());
                if (j >= i) {
                    back.insert({costs[j], -j});
                    --j;
                }
            }
        }
        return ret;
    }
};
