//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int lcs(string &s1 , string &s2, int i, int j, vector<vector<int>> &dp){
        if(i == s1.size() || j == s2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = max(lcs(s1, s2, i+1, j,dp), lcs(s1, s2, i , j+1,dp) );
        if(s1[i] == s2[j]){
            ans = max(ans, 1 + lcs(s1, s2, i+1, j+1,dp));
        }
        return dp[i][j] = ans;
    }
    int longestPalinSubseq(string A) {
        string b = A;
        reverse(b.begin(), b.end());
        vector<vector<int>> dp(A.size(), vector<int>(b.size() , -1));
        return lcs(A, b, 0, 0, dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends