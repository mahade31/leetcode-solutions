/*
Problem: https://leetcode.com/problems/counting-words-with-a-given-prefix

Solution:
	Time: O(n*m)
	Space: O(1)
*/

public class Solution {
    public int PrefixCount(string[] words, string pref) {
        var ret = 0;
        foreach (var word in words) {
            if (word.StartsWith(pref)) ++ret;
        }
        return ret;
    }
}