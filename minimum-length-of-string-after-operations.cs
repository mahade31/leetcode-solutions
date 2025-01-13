/*
Problem: https://leetcode.com/problems/minimum-length-of-string-after-operations


Solution:
	Time: O(n * log(m))
	Space: O(1)

*/
public class Solution {
    public int MinimumLength(string s) {
        var count = new Dictionary<char, int>();
        foreach (var c in s) {
            if (count.ContainsKey(c)) {
                ++count[c];
            }
            else {
                count.Add(c, 1);
            }
        }
        int ret = 0;

        foreach (var kv in count) {
            if (kv.Value % 2 == 0) ret += 2;
            else ++ret;
        }

        return ret;
    }
}