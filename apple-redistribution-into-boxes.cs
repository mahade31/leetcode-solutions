//problem: https://leetcode.com/problems/apple-redistribution-into-boxes/

//solution
public class Solution {
    public int MinimumBoxes(int[] apple, int[] capacity) {
        int total_apple = apple.Sum();

        Array.Sort(capacity);
        Array.Reverse(capacity);

        int ret = 0;
        int i = 0;

        while (total_apple > 0) {
            ++ret;
            total_apple -= capacity[i];
            ++i;
        }

        return ret;
    }
}
