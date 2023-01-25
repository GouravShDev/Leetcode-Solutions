//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        int ans = s.size();
        int mx = 0;
        for(int i = 0; i < s.size() ; i++){
            int k = 0;
            bool isFound = true;
            for(int j = i+1 ; j< s.size() && k <= i; j++){
                if(s[j] != s[k]){
                    isFound = false;
                    break;
                }
                k++;
            }
            if(isFound && k == i+1){
                mx = max(mx , i+1);
            }
        }
        return mx > 0 ? ans - mx + 1 : ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends