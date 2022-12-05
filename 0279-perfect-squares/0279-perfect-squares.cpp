class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        dp[1]= 1;
        for(int i = 1 ; i <= n ; i++){
            int minNum = INT_MAX;
            int c = 1;
            for(int j = 1; j <= i ; j = c * c){
                minNum = min(minNum, 1 + dp[i-j]);
                c++;
            }
            dp[i] = minNum;
        }
        
        return dp[n];
    }
};