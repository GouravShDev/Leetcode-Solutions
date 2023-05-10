//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        if(A.size() == 1 ) return 0;
        int ans = 0;
        vector<int> suffixMn(N, INT_MAX);
        int prevMn = INT_MAX;
        for(int i = A.size() - 1; i >= 0 ;i--){
            suffixMn[i] = prevMn = min(A[i] , prevMn);
        }
        
        int curMx = INT_MIN;
        for(int i = 0 ; i < A.size()-1; i++){
            curMx = max(curMx, A[i]);
            
            if(curMx + suffixMn[i+1] >= K) ans++;
        }
       return ans;
    }
};

// 1 3 2 1
// 1

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends