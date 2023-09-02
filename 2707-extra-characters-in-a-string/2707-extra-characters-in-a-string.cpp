class Solution {
public:
    int solve(string &s, set<string> &dict, int i, vector<int> &dp ){
        if(i == s.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 1 + solve(s, dict, i+1,dp);
        string cur = "";
        for(int j = i; j < s.size(); j++){
            cur += s[j];
            if(dict.count(cur)){
                ans = min(ans, solve(s, dict, j+1,dp));
            }
        }
        return dp[i] = ans;
            
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string> st;
        vector<int> dp(s.size(), -1);
        for(auto &k : dictionary){
            st.insert(k);
        }
        return solve(s, st, 0, dp);
    }
};