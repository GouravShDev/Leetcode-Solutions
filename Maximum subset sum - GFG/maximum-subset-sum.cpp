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
        vector<vector<long long>> dp(N, vector<long long>(2, -1));
        dp[N-1][0] = A[N-1];
        dp[N-1][1] = A[N-1] >= 0 ? A[N-1] : 0;
        for(int index = N-2 ; index >= 0; index--){
            if(A[index] < 0){
                long long ans  = INT_MIN;
                
                    ans = max(ans, dp[index+1][false]);
                    
                
                    ans = max(ans, dp[index][false] = A[index] + dp[index+1][true]);
                    dp[index][true] = ans;
            
            }else{
                dp[index][1]= A[index] + dp[index+1][true];
                dp[index][0] = dp[index][1];
            } 
        }
        // return solve(0 , A, true, dp);
        return dp[0][1];
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