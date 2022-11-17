/*
Problem: https://leetcode.com/problems/reverse-prefix-of-word/


Solution:
*/
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int ind = -1;
        for (int i = 0; i < word.length(); ++i){
            if (word[i] == ch){
                ind = i;
                break;
            }
        }
        for (int i = 0, j = ind; i < j; ++i, --j){
            swap(word[i], word[j]);
        }
        return word;
    }
};
