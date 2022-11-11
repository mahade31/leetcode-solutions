/*
Problem: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
Editorial:
For each character of the given string we just need to check if the last character of resulting string is equal to it. If equal we remove the last character of the given string and ignore the the current character otherwise we add the current character to the resulting string.

Solution:
*/
class Solution {
public:
    string removeDuplicates(string s) {
        string ret;
        for (char c : s){
            if (ret.length() > 0 and ret.back() == c){
                ret.pop_back();
            }
            else
                ret += c;
        }
        return ret;
    }
};
