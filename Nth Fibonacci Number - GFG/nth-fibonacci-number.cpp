//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    
    int nthFibonacci(int n){
        int mod = 1e9+7;
        int ans = 1;
        int prev = 0;
        for(int i = 1  ; i < n;i++){
            int temp = ans;
            ans = (ans + prev) % mod;
            //cout<<ans<<" ";
            prev =temp;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends