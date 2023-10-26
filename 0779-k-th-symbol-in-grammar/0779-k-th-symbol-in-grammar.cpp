class Solution {
public:
    int kthGrammar(int n, int k) {
        bool isOn = false;
        long long x = pow(2, n-1);
        while(x>1){
            x >>=1;
            if(k > x){
                k-=x;
                isOn= !isOn;
            }
        }
        return isOn;
    }
};

/*

0 - 0
01 - 1
0110 - 6
01101001 - 105

*/