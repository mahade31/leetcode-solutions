/*

This is a very basic problem, we just need to check if the given integer is a palindrome or not. A palindromic number is a number which remains same when its digits are reversed. 
We can reverse an integer by appending the last digit of a number to the last of a new number till there is a digit left to the original number.

We can get the last digit by taking the remainder when divided by 10.
We can add it to the last by multiplying the previous number by 10 and then adding the digit.

There are two things to keep in mind. First, any negative number cannot be a palindrome. Second, the reversal of a 31-bit number can be more than 31-bit. So we need to use 63 bits to store the reversed number.

*/

class Solution {
public:
    int reverse(int x){
        long long reversedNumber = 0;
        while (x > 0){
            reversedNumber = reversedNumber * 10 + (x % 10);
            x /= 10;
        }
        return reversedNumber;
    }
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        return (x == reverse(x));
    }
};
