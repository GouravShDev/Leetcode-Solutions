class Solution {
public:
    vector<int> dp;
    int fact(int n){
        if(n == 0) return 1;
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(dp[n] != -1) return dp[n];
        return dp[n] = n * fact(n-1);
    }
    void solve(int n , int k , vector<int>& cur ,string &ans){
        if(n == 0) return;
        int factN = fact(n-1);
        ans += to_string(cur[k / factN]);
        cur.erase(cur.begin() + (k/factN));
        solve(n-1,  k%factN , cur, ans);
    }
    string getPermutation(int n, int k) {
        dp.resize(n+1, -1);
        vector<int> nums(n);
        iota(nums.begin(), nums.end() ,1);
        string ans = "";
        solve(n , k-1 , nums, ans);
        return ans;
    }
};