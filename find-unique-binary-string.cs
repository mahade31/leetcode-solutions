


public class Solution {
    public string FindDifferentBinaryString(string[] nums) {
        int len = nums.Count();

        for (int i = 0; i <= len; ++i) {
            string binary_string = GetBinaryStringFromNumber(i, len);
            if (!nums.Contains(binary_string)) return binary_string;
        }
        return "-1";
    }

    string GetBinaryStringFromNumber(int a, int len) {
        string num = "";
        while (a > 0) {
            num =(((a % 2) == 1) ? '1' : '0') + num;
            a /= 2;
        }

        while (num.Count() < len) {
            num = '0' + num;
        }
        return num;
    }

}