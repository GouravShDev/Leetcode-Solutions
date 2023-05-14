//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
    long long solve(int index, vector<int> &A,bool lastPicked, vector<vector<int>> &dp){
        if(index == A.size()) return 0;
        long long ans  = INT_MIN;
        if(dp[index][lastPicked] != -1) return dp[index][lastPicked];
        if(A[index] < 0){
            if(lastPicked){
                ans = max(ans, solve(index+1, A, false, dp));
            }
                ans = max(ans, A[index] + solve(index+1, A,true, dp));
            
        }else{
            ans = A[index] + solve(index+1, A, true, dp);
        }
        
        return dp[index][lastPicked] = ans;
    }
    long long findMaxSubsetSum(int N, vector<int> &A) {
        vector<vector<int>> dp(N, vector<int>(2, -1));
        return solve(0 , A, true, dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends