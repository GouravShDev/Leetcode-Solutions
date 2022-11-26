class Solution {
public:
    vector<int> dp;
    int fact(int n){
        if(n == 0) return 1;
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = n * fact(n-1);
    }
    void solve(int n , int k, vector<int> &sequence, string &ans){
        if( n == 0 )return ;
        int factN= fact(n-1);
        int num = sequence[k / factN];
        ans+= to_string(num);
        sequence.erase( sequence.begin() + (k/factN));
        solve(n-1, k % factN , sequence, ans);
    }
    string getPermutation(int n, int k) {
        dp.resize(n+1,-1);
        vector<int> sequence(n);
        string ans="";
        iota(sequence.begin(), sequence.end() , 1);
        solve(n , --k , sequence, ans);
        return ans;
    }
};