//problem: https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ret = 0;
        for (int i = 0; i <= 30; ++i) {
            bool bit_c = (c & (1 << i));
            bool bit_a = (a & (1 << i));
            bool bit_b = (b & (1 << i));
            if (bit_c) {
                ret += !(bit_a or bit_b);
            }
            else {
                ret += bit_a;
                ret += bit_b;
            }
        }
        return ret;
    }
};
