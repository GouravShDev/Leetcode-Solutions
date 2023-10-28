//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int solve(string S, string rev, int i, int j,vector<vector<int>> &dp){
        if(i== S.size() || j == rev.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(S[i] == rev[j]) return dp[i][j] = 1 + solve(S, rev, i+1, j+1,dp);
        return dp[i][j] =max(solve(S, rev, i+1, j,dp) , solve(S, rev, i, j+1,dp));
    }
    int minimumNumberOfDeletions(string S) { 
        string rev = S;
        reverse(rev.begin(), rev.end());
        vector<vector<int>> dp(S.size()+1 , vector<int>(rev.size()+1,0));
        for(int i = 1 ; i <= S.size() ; i++){
            for(int j=1 ; j <= S.size() ; j++){
                if(S[i-1] == rev[j-1]){
                    dp[i][j]= 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return S.size() - dp[S.size()][S.size()];
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends