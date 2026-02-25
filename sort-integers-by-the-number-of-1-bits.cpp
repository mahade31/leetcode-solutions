//problem: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits

//time: O(n^2 * 20) = O(n^2)
//space: O(1)

//solution

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = i + 1; j < arr.size(); ++j) {
                int bitA = 0;
                int bitB = 0;
                for (int k = 0; k < 20; ++k) {
                    if (arr[i] & (1 << k)) ++bitA;
                    if (arr[j] & (1 << k)) ++bitB;
                }
                if (bitA > bitB || (bitA == bitB && arr[i] > arr[j])){
                    swap(arr[i], arr[j]);
                }
            }
        }
        return arr;
    }
};