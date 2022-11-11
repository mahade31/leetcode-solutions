/*
Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

Editorial:
Trick to solve this problem is there can be at most 201 unique numbers in the array.

So for first 201 numbers in the array, we checked which ones are the duplicates, meaning there is already the same number before this one. If a number is a duplicate then we replaced that with 200, 200 is a flag here to remember that this place can be replaced with another number. Then for each elements of the array we check if this is the first occurence, if it is then we put it to the first available place (in place of first 200 we can find).

So the overall complexity is O(201 * n).
And space complexity in O(1) because we did not use any auxilary space as asked. 

Solution:
*/


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int last = -1;
        for (int i = 1; i < min(202, (int)nums.size()); ++i){
            for (int j = 0; j < i; ++j){
                if (nums[i] == nums[j]){
                    nums[i] = 200;
                    break;
                }
            }
        }
    
        for (int i = 1; i < nums.size(); ++i){
            bool found = false;
                for (int j = 0; j < min(201, i); ++j){
                    if (nums[j] == nums[i]){
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    for (int j = 0; j < min(201, i); ++j){
                        if (nums[j] == 200){
                            swap(nums[i], nums[j]);
                            break;
                        }
                    }
                }
            }
        
        for (int i = 1; i < nums.size(); ++i){
            if (nums[i] == 200)
                return i;
        }
        
        return nums.size();
    }
};
