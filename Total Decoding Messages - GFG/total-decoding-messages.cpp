//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int mod = 1e9+7;
	public:
		int CountWays(string str){
		    return numDecodings(str);
		}
int numDecodings(string s) {
        vector<int> dp(s.size()+1, 1);
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] == '0'){
                dp[i] = 0;
            }else{
                int single = dp[i+1];
                int doublePick= 0;
                if(i < s.size()-1 && (s[i] == '1' ||(s[i] == '2' && s[i+1] < '7'))) doublePick = dp[i+2];
                dp[i] = (single + doublePick) % mod;
            }
        }
        return dp[0] % mod;
    }
    int numDecodings(int p, string& s) {
        int n = s.size();
        if(p == n) return 1;
        if(s[p] == '0') return 0; // sub string starting with 0 is not a valid encoding
        int res = numDecodings(p+1,s);
        if( p < n-1 && (s[p]=='1'|| (s[p]=='2'&& s[p+1]<'7'))) res += numDecodings(p+2,s);
        return res;
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
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends