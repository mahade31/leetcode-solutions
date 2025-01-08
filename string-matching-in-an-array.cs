/*
Problem: https://leetcode.com/problems/string-matching-in-an-array/description/


Solution:
		Time: O(n*m)
		Space: O(n)
*/
public class Solution {
    public IList<string> StringMatching(string[] words) {
        List <string> ret = new List<string>();
        for (int i = 0; i < words.Count(); ++i) {
            for (int j = 0; j < words.Count(); ++j) {
                if (i != j && words[j].Contains(words[i])) {
                    ret.Add(words[i]);
                    break;
                }
            }
        }
        return ret;
    }
}