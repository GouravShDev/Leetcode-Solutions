//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int lcs(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
	        if(i == s1.size() || j == s2.size()){
	            return 0;
	        }
	        if(dp[i][j] != -1) return dp[i][j];
	        int ans = lcs(s1, s2, i+1,j,dp);
	        ans= max(ans, lcs(s1, s2, i, j+1,dp));
	        if(s1[i] == s2[j] && i != j){
	            ans = max(ans, 1 + lcs(s1, s2, i+1, j+1,dp));
	        }
	        return dp[i][j]=  ans;
	    }
		int LongestRepeatingSubsequence(string str){
		    vector<vector<int>> dp(str.size(), vector<int>(str.size(),-1));
		    return lcs(str, str, 0, 0,dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends