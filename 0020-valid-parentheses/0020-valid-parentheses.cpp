class Solution {
public:
    bool isOpenBracket(char c){
        return c == '(' || c == '{' || c == '[';
    }
    bool isValid(string s) {
        vector<char> stk;
        for(int i = 0; i< s.size(); i++){
            if(isOpenBracket(s[i])){
                stk.push_back(s[i]);
            }else{
                char current = s[i];
                if(stk.empty()) return false;
                if(stk.back() == '(' && current == ')'){
                    stk.pop_back();
                }else if(stk.back() == '{' && current == '}'){
                    stk.pop_back();
                }else if(stk.back() == '[' && current == ']'){
                    stk.pop_back();
                }else{
                    return false;
                }
            }
        }
        return stk.empty();
    }
};