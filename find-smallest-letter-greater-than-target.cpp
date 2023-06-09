//problem: https://leetcode.com/problems/find-smallest-letter-greater-than-target/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start = 0, end = letters.size() - 1;
        char ret = letters[0];
        while (start <= end) {
            int mid = (start + end) / 2;
            if (letters[mid] > target) {
                ret = letters[mid];
                end = mid - 1;
            }
            else 
                start = mid + 1;
        }
        return ret;
    }
};
