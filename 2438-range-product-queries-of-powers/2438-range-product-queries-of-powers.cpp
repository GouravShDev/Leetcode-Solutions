class Solution {
public:
    int MOD = 1e9+ 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
     vector<int> powers;
        for(int i = 0 ; i< 32; i++){
            int mask = 1 << i;
            if(mask & n){
                powers.push_back(mask);
            }
        }
        vector<int> ans(queries.size());
        for(int i =0 ; i < queries.size(); i++){
            int start = queries[i][0];
            int end = queries[i][1];
            long long x = 1;
            while(start <= end){
                x = (x * powers[start++]) % MOD;
            }
            ans[i] = x;
        }
        return ans;
    }
};