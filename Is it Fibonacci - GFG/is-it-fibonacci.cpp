//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int n, int K, vector<long long> GeekNum) {
        long long curSum = 0;
        int start = 0;
        for(int i = 0 ;i < n; i++){
            if(i < GeekNum.size()){
                curSum += GeekNum[i];
                continue;
            }
            GeekNum.push_back(curSum);
            // cout<<GeekNum.back();
            curSum += curSum;
            curSum -= GeekNum[start++];
            
        }
        return GeekNum.back();
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends