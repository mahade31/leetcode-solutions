//solution:
class Solution {
public:
    int jump(vector<int>& nums) {
        int res[nums.size()];
        for (int i = 0; i < nums.size(); ++i)
            res[i] = 1e5;
        res[0] = 0;
        for (int i = 0; i < nums.size() - 1; ++i){
            int k = min(i + nums[i], (int)nums.size() - 1);
            for (int j = i + 1; j <= k; ++j)
                res[j] = min(res[j], res[i] + 1);
        }
        return res[nums.size() - 1];
    }
};
