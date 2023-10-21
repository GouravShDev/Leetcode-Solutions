//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
long long  dp[1000001];
class Solution
{
public:
 
    long long solve(int n){
        long long ans = 0;
        if(dp[n] != 0) return dp[n];
        for(int i = 1 ; i * i <= n ; i++){
            if(n % i == 0){
                int d = n/ i;
                ans += i;
                if(d != i) ans += d;
            }
        }
        return dp[n] = ans;
    }
    long long sumOfDivisors(int n)
    {
        long long ans = 0;
        for(int i = 1 ; i  <= n ; i++){
            ans += i*(n/i);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        long long ans  = ob.sumOfDivisors(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends