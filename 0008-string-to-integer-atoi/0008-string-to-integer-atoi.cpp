class Solution {
public:
    int myAtoi(string s) {
        
        int ans = 0;
        int i = 0;
        bool isNeg = false;
        
        // ignore whitespaces
        
        while(i < s.size() && s[i] == ' ') i++;
        
        // check for sign
        if(i < s.size() && (s[i] == '+' || s[i] == '-')){
            if(s[i++] == '-'){
                isNeg = true;
            }
        }
        
        while(i < s.size() && s[i] >= '0' && s[i] <= '9'){
            // check for overflow
            // 24.......
            // 214748364    7
            if( INT_MAX / 10 < ans || ( INT_MAX /10 == ans && s[i] > '7')){
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