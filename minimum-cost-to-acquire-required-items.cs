//problem: https://leetcode.com/problems/minimum-cost-to-acquire-required-items/

//solution:
public class Solution {
    public long MinimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long ret = 0;
        if (cost1 + cost2 > costBoth) {
            var min = Math.Min(need1, need2);
            ret += (long)min * costBoth;
            need1 -= min;
            need2 -= min;
        }
        if (cost1 < costBoth) {
            ret += (long)need1 * cost1;
        }
        else {
            ret += (long)need1 * costBoth;
            need2 -= need1;
        }

        if (cost2 < costBoth) {
            ret += (long)Math.Max(0, need2) * cost2;
        }
        else {
            ret += (long)Math.Max(0, need2) * costBoth;
        }

        return ret;
    }
}