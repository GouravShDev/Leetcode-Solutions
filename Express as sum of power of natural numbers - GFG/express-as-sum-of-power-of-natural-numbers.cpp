//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int mod= 1e9 + 7;
    int solve(int n , int x, int number,vector<vector<int>> &dp){
        if(n == 0) return 1;
        if(n < 0 ) return 0; 
        if(number == 0 ) return 0;
        if(dp[n][number] !=-1) return dp[n][number];
        return dp[n][number] = ((solve(n, x , number-1,dp)) % mod + (solve(n- pow(number,x), x, number-1,dp)) % mod) % mod;
    }
    int numOfWays(int n, int x)
    {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1)); 
        return solve(n , x,n, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends