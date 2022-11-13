/*
Problem: https://leetcode.com/problems/reverse-words-in-a-string/

Solution:
*/

class Solution {
public:
    string reverseWords(string s) {
        string res;
        string temp;
        s += ' ';
        for (char c : s){
            if (c != ' ')
                temp += c;
            else if (!temp.empty()) {
                reverse(temp.begin(), temp.end());
                res += temp;
                res += ' ';
                temp = "";
            }
        }
        res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};
