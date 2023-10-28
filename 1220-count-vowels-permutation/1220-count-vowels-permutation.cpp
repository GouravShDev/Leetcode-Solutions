class Solution {
public:
    int countVowelPermutation(int n) {
        vector<long long> dp(5, 1);
        vector<long long> prev = dp;
        int mod = 1e9+7;
        map<char, int> mp = {
            {'a', 0},
            {'e', 1},
            {'i', 2},
            {'o', 3},
            {'u', 4},
        };
        for(int i = 1 ;i < n; i++){
            dp[mp['a']] = (prev[mp['e']] + prev[mp['i']] + prev[mp['u']]) % mod;
            dp[mp['e']] = (prev[mp['a']] + prev[mp['i']]) % mod;
            dp[mp['i']] = (prev[mp['e']] + prev[mp['o']]) % mod;
            dp[mp['o']] = prev[mp['i']];
            dp[mp['u']] = (prev[mp['o']] + prev[mp['i']])% mod;
            prev = dp;
        }
        int ans = 0;
        for(auto &i : prev){
            ans = (ans + i)%mod;
        }
        return ans;
        
    }
};