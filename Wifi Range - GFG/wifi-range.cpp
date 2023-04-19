//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        int rightRange = -1;
        int leftRange = N;
        int ans = 0;
        vector<int> wifiAvailable(N);
        for(int i =0 ; i < S.size() ; i++){
            if(S[i] == '1'){
                rightRange = i + X + 1 ;
            }
            if(i < rightRange) wifiAvailable[i] = 1;
        }
        for(int j = S.size() - 1 ; j >= 0; j--){
            if(S[j] == '1'){
                leftRange = j - X - 1;
            }
            if(j > leftRange) wifiAvailable[j] = 1;
        }
        for(auto &it : wifiAvailable){
            if(it) ans++;
        }
        return ans == N;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends