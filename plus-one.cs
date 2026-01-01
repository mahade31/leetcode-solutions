//problem: https://leetcode.com/problems/plus-one


//solution
public class Solution {
    public int[] PlusOne(int[] digits) {
        int n = digits.Count();
        int carry = 1;
        for (int i = n - 1; i >= 0; --i) {
            int currentSum = digits[i] + carry;
            if (currentSum > 9) {
                digits[i] = 0;
                carry = 1;
            }
            else {
                digits[i] = currentSum;
                carry = 0;
            }
        }

        var list = digits.ToList();

        if (carry > 0) {
            list.Insert(0, carry);
        }

        return list.ToArray();
    }
}