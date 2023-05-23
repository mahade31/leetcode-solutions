//problem: https://leetcode.com/problems/kth-largest-element-in-a-stream/



class KthLargest {
public:
    multiset <int> big;
    int K;
    KthLargest(int k, vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        for (int i = 0; i < min((int)nums.size(), k); ++i)
            big.insert(nums[i]);
        K = k;
    }
    
    int add(int val) {
        if (big.size() < K){
            big.insert(val);
            return *big.begin();
        }

        int big_top = *big.begin();
        if (val > big_top){
            big.erase(big.begin());
            big.insert(val);
        }

        return *big.begin();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
