//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int i = 0;
        vector<int> mp(26,0);
        int ans = -1;
        for(int j = 0 ; j < s.size(); j++){
            mp[s[j]-'a']++;
            int uniqueCount = accumulate(mp.begin(), mp.end(), 0 , [](auto &acc, auto &cur){
                return acc + (cur > 0 ? 1 : 0);
            });
            while(uniqueCount > k &&  i < j){
                mp[s[i]-'a']--;
                i++;
                uniqueCount = accumulate(mp.begin(), mp.end(), 0 , [](auto &acc, auto &cur){
                return acc + (cur > 0 ? 1 : 0);
            });
            }
            if(uniqueCount == k)ans =max(ans, j- i + 1);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends