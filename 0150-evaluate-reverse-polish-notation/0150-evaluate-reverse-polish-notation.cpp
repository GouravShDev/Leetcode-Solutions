#define ll long long
class Solution {
public:
    ll solveOp(ll a, ll b , char op){
        if(op == '+'){
            return a + b;
        }else if(op == '-'){
            return a- b;
        }else if(op == '*'){
            return a * b;
        }else{
            return a/b;
        }
    }
    bool isOperator(string c){
        return (c == "+") || (c == "-") || (c == "*") || (c == "/");
    }
    int evalRPN(vector<string>& tokens) {
        stack<ll> stk;
        for(auto &ch : tokens){
            if(isOperator(ch)){
                ll b = stk.top();stk.pop();
                ll a = stk.top();stk.pop();
                stk.push(solveOp(a, b, ch[0]));
            }else{
                stk.push(stoi(ch));
            }
        }
        return stk.top();
    }
};