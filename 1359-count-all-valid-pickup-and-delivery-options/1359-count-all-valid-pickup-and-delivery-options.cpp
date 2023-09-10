class Solution {
public:
    int mod = 1e7 + 9;
    // set<vector<int>> st;
    int solve(int n , int index, vector<int> &services, vector<int> &dp){
        if(index == n){
            int count = accumulate(services.begin(), services.end(), 0 );
            // if(st.count(services)) return 0;
            // st.insert(services);
            return count > 0 ? 0 : 1;
        }
        if(dp[index] != -1) return dp[index];
        int ans = 0;
        for(int i =0 ; i < services.size() ; i++){
            if(services[i] == -1) continue;
            int choice = -1;
            if(services[i] == 0){
                choice = 1;
            }else{
                choice = -1;
            }
            services[i] = choice;
            ans = (ans + solve(n, index+1, services,dp)) % mod;
            services[i] = 0;
        }
        return dp[index] = ans;
    }
    int countOrders(int n) {
        long res = 1, mod = 1e9 + 7;
        for (int i = 1; i <= n; ++i)
            res = res * (i * 2 - 1) * i % mod;
        return res;
    }
};