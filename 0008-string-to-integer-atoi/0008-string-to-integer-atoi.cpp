class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int ans = 0;
        bool isNeg = false;
        while(i < s.size() && s[i] == ' ')i++;
        if(i < s.size() && (s[i] == '-' || s[i] == '+')){
            isNeg = (s[i++] == '-');
        }
        while(i < s.size() && s[i] >= '0' && s[i] <= '9'){
            if(INT_MAX/10 < ans || (INT_MAX / 10 == ans && s[i] > '7') ){
                if(isNeg){
                    return INT_MIN;
                }else{
                    return INT_MAX;
                }
            }
            ans *= 10;
            ans += s[i++] - '0';
        }
        return isNeg ? -ans : ans;
    }
};