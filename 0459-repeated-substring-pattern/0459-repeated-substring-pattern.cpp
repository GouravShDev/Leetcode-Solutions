class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string cur= "";
        for(int i =0 ;i < s.size(); i++){
            cur+= s[i];
            for(int j = i+1; j < s.size();j++){
                if(cur[j % cur.size()] != s[j]) break;
                if(j == s.size()-1 && ((j % cur.size()) == cur.size()-1)) return true;
            }
        }
        return false;
    }
};