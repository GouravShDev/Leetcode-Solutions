class Solution {
public:
    string reverseWords(string s) {
        
        string ans = "";
            string cur = "";
        for(int i =0 ; i <= s.size() ;i++){
            if(i == s.size() || s[i] == ' '){
                if(cur.empty()) continue;
                ans.insert(0, cur + " ");
                cur = "";
            }else{
                cur+= s[i];
            }
        }
        ans.pop_back();
        return ans;
    }
};