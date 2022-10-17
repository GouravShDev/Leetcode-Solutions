class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int sum = 0;
        for(int i = 0; i < 32; i++){
            int mask = 1 << i;
            bool abit = a & mask;
            bool bbit = b & mask;
            int bit = (abit ^ bbit ^ carry);
            if(bit) sum = sum | mask;
            carry = (abit & bbit) || (abit & carry) || (bbit & carry);
            // cout<<carry<<" ";
        }
        return sum;
    }
};