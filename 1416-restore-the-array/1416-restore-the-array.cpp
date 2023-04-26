class Solution {
public:
    int mod = 1e9 + 7;
    int solve(string &s, int index, int k, vector<int> &dp){
        if(index == s.size()) return 1;
        if(s[index] == '0') return 0;
        if(dp[index] != -1) return dp[index];
        int sum = 0;
        long num = 0;
        for(int i =index ; i < s.size(); i++){
            num *= 10;
            num += (s[i] - '0');
            if(num > k) break;
            sum = ((solve(s, i+1, k,dp) * 1ll + sum) % mod);
        }
        return dp[index] = sum;
    }
    int numberOfArrays(string s, int k) {
        vector<int> dp(s.size(), -1);
        return solve(s, 0, k, dp);
    }
};