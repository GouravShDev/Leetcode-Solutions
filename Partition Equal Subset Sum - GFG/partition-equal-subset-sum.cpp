//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool solve(int arr[], int i , int n, int sum,vector<vector<int>> &dp){
        if(sum < 0) return false;
        if(i == n){
            return sum == 0;
        }
        if(dp[i][sum] != -1) return dp[i][sum];
        return dp[i][sum]   = solve(arr, i +1, n , sum - arr[i],dp) || solve(arr, i +1 , n , sum,dp);
    }
    int equalPartition(int N, int arr[])
    {
        int sum  = accumulate(arr, arr+N,0);
        if(sum & 1) return 0;vector<vector<int>> dp(N , vector<int>(sum , -1));
        
        return solve(arr, 0, N, sum/2,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends