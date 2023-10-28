class Solution {
private: 
    int mod = 1e9+7;
public:
    
    int solve(int n , char lastCh, map<char, vector<char>> &mp,vector<vector<int>> &dp){
        if(n == 0) return 1;
        if(dp[n][lastCh-'a'] != -1) return dp[n][lastCh-'a'];
        int ans = 0;
        for(auto &c : mp[lastCh]){
            ans = (ans + solve(n-1, c, mp,dp)) % mod;
        }
        return dp[n][lastCh-'a'] = ans;
    }
    int countVowelPermutation(int n) {
        map<char, vector<char>> mp = {
            {'a', {'e'}},
            {'e', {'a', 'i'}},
            {'i', {'a', 'e','o','u'}},
            {'o', {'i','u'}},
            {'u', {'a'}}
        };
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(26,-1));
        for(auto &it: mp){
           ans = (ans + solve(n-1, it.first, mp,dp)) % mod; 
        }
        return ans;
    }
};