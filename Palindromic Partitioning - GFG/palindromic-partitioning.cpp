//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(string &str, int i , vector<vector<bool>> &isPalindrome,vector<int> &dp){
        if(i == str.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        for(int j = i ; j < str.size() ;j++){
            if(isPalindrome[i][j]){
                ans =min(ans , solve(str, j+1,isPalindrome,dp));
            }
        }
        dp[i] = ans+1;
        return ans + 1;
    }
    int palindromicPartition(string str)
    {
        vector<vector<bool>> isPalindrome(str.size(), vector<bool>(str.size()));
        for(int index = 0 ;index < str.size() ; index++){
            int i = index;
            int j = index;
            while(i >= 0 && j < str.size() && str[i] == str[j]){
         
                isPalindrome[i--][j++] = 1;
            }
            i = index-1;
            j = index;
            while( i >= 0 && j < str.size() && str[i] == str[j]){
               
                 isPalindrome[i--][j++] = 1;
            }
        }
        
        vector<int> dp(str.size(), -1);
        return solve(str, 0,isPalindrome, dp)-1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends