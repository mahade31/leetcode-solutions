//problem: https://leetcode.com/problems/powx-n/

//built-in pow
class Solution {
public:
    double myPow(double x, int n) {
       return pow(x,n);
    }
};

//binary exponentiation

class Solution {
private:
    double binary_expo(double x, long long n) {
        if (n == 0) return 1;
        if (n < 0) return binary_expo(1.00/x, -n);
        if ((n & 1)) return x * binary_expo(x * x, n / 2);
        return binary_expo(x * x, n / 2);
    }
public:
    double myPow(double x, int n) {
       return binary_expo(x,n);
    }
};
