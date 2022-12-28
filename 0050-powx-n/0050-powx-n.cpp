class Solution {
public:
    double myPow(double x, int n) {
        bool isNegative = n < 0;
        n = abs(n);
        double res = 1.0;
        while(n>0)
        {
            if(n & 1){
                res *= x;
                n -= 1;
            }
            x = (x * x);
            n/=2;
        }
        return isNegative ? (1/ res) : res;
    }
};