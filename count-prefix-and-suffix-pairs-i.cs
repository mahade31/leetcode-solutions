/*
Problem: https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/

Solution:
	Time: O(n * m)
	Space: O(1)
*/
public class Solution {
    public int CountPrefixSuffixPairs(string[] words) {
        int ret = 0;
        for (int i = 0; i < words.Count(); ++i) {
            for (int j = i + 1; j < words.Count(); ++j) {
                if (words[j].StartsWith(words[i]) && words[j].EndsWith(words[i])) {
                    ++ret;
                }
            }
        }
        return ret;
    }
}