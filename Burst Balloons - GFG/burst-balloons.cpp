//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int solve(vector<int> &arr, int i, int j, vector<vector<int>> &dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MIN;
        for(int index = i; index <= j ; index++){
            ans = max(ans,(arr[i-1] * arr[index] * arr[j+1])  +  solve(arr, i , index-1,dp) + solve(arr, index+1, j,dp));
        }
        return dp[i][j] =  ans;
    }
    int maxCoins(int N, vector<int> &arr) {
        arr.insert(arr.begin(),1);
        arr.push_back(1);
        vector<vector<int>> dp(N+2 , vector<int>(N+2,-1));
        return solve(arr, 1 , arr.size()-2,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends