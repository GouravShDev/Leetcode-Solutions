class Solution {
public:
    int calculate(string s) {
        int ans = 0 ;
        int curNo = 0;
        int sign = 1;
        stack<int> stk;
        for(int i = 0 ;i < s.size() ; i++){
            if(s[i] >= '0' && s[i] <= '9'){
                curNo *= 10;
                curNo += s[i] - '0';
            }else if(s[i]== '+'){
                curNo *= sign;
                ans += curNo;
                curNo = 0;
                sign = 1;
            }else if(s[i] == '-'){
                curNo *= sign;
                ans += curNo;
                curNo = 0;
                sign = -1;
            }else if(s[i] == '('){
                curNo *= sign;
                ans += curNo;
                curNo = 0;
                
                stk.push(ans);
                stk.push(sign);
                ans = 0;
                sign = 1;
            }else if(s[i] == ')') {
                curNo *= sign;
                ans += curNo;
                curNo = 0;
                
                ans = stk.top() * ans;
                stk.pop();
                ans += stk.top();
                stk.pop();
                
            }
        }
                curNo *= sign;
                ans += curNo;
                curNo = 0;
        return ans;
    }
};