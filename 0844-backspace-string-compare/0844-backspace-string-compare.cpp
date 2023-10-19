class Solution {
public:
    void solve(string &s, string &ans){
        int i = 0 ;
        while(i < s.size()){
            while(i < s.size() && s[i] == '#'){
                if(ans.size())ans.pop_back();
                i++;
            }
            if(i < s.size()) ans.push_back(s[i]);
            i++;
        }
    }
    bool backspaceCompare(string s, string t) {
        string ss;
        string tt;
        solve(s, ss);
        solve(t, tt);
        // cout<<ss<<" " << tt;
        return ss== tt;
    }
};