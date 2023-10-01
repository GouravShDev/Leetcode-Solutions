class Solution {
public:
    string reverseWords(string s) {
        string ans;
        string cur;
        for(int i = 0 ;i <= s.size(); i++){
            if( i == s.size() || s[i] == ' '){
                reverse(cur.begin(), cur.end());
                ans += cur;
                ans += ' ';
                cur = "";
            }else{
                cur += s[i];
            }
            
        }
        ans.pop_back();
        return ans;
    }
};