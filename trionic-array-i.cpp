//problem : https://leetcode.com/problems/trionic-array-i/description/

//time : O(n) , space : O(1)

//solution
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        if (nums[0] >= nums[1]) return false;
        int stage = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (stage == 1) {
                if (nums[i - 1] >= nums[i]) ++stage;
            }
            if (stage == 2) {
                if (nums[i - 1] <= nums[i]) ++stage;
            }
            if (stage == 3) {
                if (nums[i - 1] >= nums[i]) ++stage;
            }
        }
        return stage == 3;
    }
};