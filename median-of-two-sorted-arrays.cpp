/*
Problem: https://leetcode.com/problems/median-of-two-sorted-arrays/

Editorial: 


Complexity: Time complexity O(log m) * O(log n)
*/
class Solution {
public:
    int findNth(vector<int>& nums1, vector<int>& nums2, int n){
        int left = 0, right = min(n - 1, (int)nums1.size() - 1);
        while (left <= right){
            int mid = (left + right) / 2;
            int smaller = (upper_bound(nums1.begin(), nums1.end(), nums1[mid] - 1) - nums1.begin()) + (upper_bound(nums2.begin(), nums2.end(), nums1[mid] - 1) - nums2.begin());
            int bigger = nums1.size() - (upper_bound(nums1.begin(), nums1.end(), nums1[mid]) - nums1.begin()) + nums2.size() - (upper_bound(nums2.begin(), nums2.end(), nums1[mid]) - nums2.begin());
            
            if (smaller < n and n <= nums1.size() + nums2.size() - bigger)
                return nums1[mid];
            else if (smaller < n)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        left = 0, right = min(n - 1, (int)nums2.size() - 1);
        while (left <= right){
            int mid = (left + right) / 2;
            int smaller = (upper_bound(nums1.begin(), nums1.end(), nums2[mid] - 1) - nums1.begin()) + (upper_bound(nums2.begin(), nums2.end(), nums2[mid] - 1) - nums2.begin());
            int bigger = nums1.size() - (upper_bound(nums1.begin(), nums1.end(), nums2[mid]) - nums1.begin()) + nums2.size() - (upper_bound(nums2.begin(), nums2.end(), nums2[mid]) - nums2.begin());
            
            if (smaller < n and n <= nums1.size() + nums2.size() - bigger)
                return nums2[mid];
            else if (smaller < n)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return -1;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total_len = nums1.size() + nums2.size();
        if (total_len % 2)
            return findNth(nums1, nums2, total_len / 2 + 1);
        else
            return (double)(findNth(nums1, nums2, total_len / 2) + findNth(nums1, nums2, total_len / 2 + 1)) / 2;
    }
};
