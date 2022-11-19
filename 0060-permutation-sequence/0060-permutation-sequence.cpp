class Solution {
public:
    vector<int> dp;
    int fact(int n){
        if(n == 0)return 1;
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = n * fact(n-1);
    }
    void solve(vector<int> numbers, int k , string &ans){
        if(numbers.size() == 1){
            ans += to_string(numbers.back());
            return;
        }
        int n = numbers.size();
        int factN = fact(n-1);
        int x =  k / factN;
        
        ans += to_string(numbers[x]);
        numbers.erase(numbers.begin() + x);
        solve(numbers, k % factN, ans);
        
    }
    string getPermutation(int n, int k) {
        string ans = "";
        vector<int> st;
        dp.resize(n+1, -1);
        for(int i =  1; i <= n; i++){
            st.push_back(i);
        }
        solve(st, --k, ans);
        return ans;
    }
};