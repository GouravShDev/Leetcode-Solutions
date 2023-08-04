class Solution {
public:    
    set<string> st;
    vector<int> dp;
    bool solve(string &s, int index){
        if(index == s.size()){
             return true;
        }
        if(dp[index] != -1) return dp[index];
        string cur;
        for(int i = index ; i < s.size(); i++){
            cur += s[i];
            if(st.count(cur) && solve(s, i+1)) return true;
        }
        return dp[index] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto &i : wordDict){
            st.insert(i);
        }
        dp = vector<int>(s.size(), -1);
        return solve(s, 0);
    }
};