class Solution {
public:
    int sumDigits(int num){
        int sum = 0;
        while(num){
            sum += num%10;
            num/=10;
        }
        return sum;
    }
    int addDigits(int num) {
        while(num > 9){
            num = sumDigits(num);
        }
        return num;
    }
};