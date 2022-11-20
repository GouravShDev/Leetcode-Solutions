class Solution {
public:
    int myAtoi(string s) {
         int ans = 0;
        int i =0 ;
        bool isNeg = false;
        while(i < s.size()){
            
            // ignore space
            while(i < s.size() && s[i] == ' ') i++;
            if( i < s.size() && (s[i] == '-' || s[i] == '+')){
                isNeg = (s[i++] == '-');
            }
            while(i < s.size() && s[i] >= '0' && s[i] <= '9'){
                if(!isNeg &&(( (INT_MAX  )/ 10 < ans) || ((s[i] - '0' > 7 && (INT_MAX  )/ 10 == ans)))){
                    return INT_MAX;
                }else if( isNeg && ( (INT_MIN )/ 10 > -ans|| ( INT_MIN/ 10 == -ans && s[i] - '0' > 7))){
                    //cout << ((INT_MIN  ) / 10 + (s[i] - '0'))<<endl;
                    return INT_MIN;
                }
                ans *= 10;
                ans += s[i++] - '0';
            }
            if(i < s.size() && (s[i] <= '0' || s[i] >= '9')){
                break;
            }
            
        }
        return isNeg ? -ans : ans;
    }
};