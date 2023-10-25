//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int val[], int wt[], int n, int index, int weight, vector<vector<int>> &dp){
        if(index == n) return 0;
        if(weight == 0) return 0;
        if(weight < 0) return INT_MIN;
        if(dp[index][weight] != -1) return dp[index][weight];
        int notPick = solve(val, wt, n , index+1, weight,dp);
        int pick = val[index] + solve(val, wt, n , index, weight - wt[index],dp);
         return dp[index][weight] = max(pick, notPick);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N, vector<int>(W+1, -1));
        
       return solve(val, wt, N , 0, W, dp);
       
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends