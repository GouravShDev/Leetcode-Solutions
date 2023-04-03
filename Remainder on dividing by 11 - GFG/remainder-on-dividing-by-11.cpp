//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++


class Solution
{

public:
    int xmod11(string x)
    {
        int evenSum = 0;
        int oddSum = 0;
        for(int i = 0; i < x.size() ;i++){
            int dig = x[i]-'0';
            if(i & 1){
                oddSum = (oddSum  + dig) % 11;
            }else{
                evenSum = (evenSum +  dig) % 11;
            }
        }
        return ((oddSum - evenSum) + 11)  % 11;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x;
        cin>>x;
        Solution ob;
        int ans = ob.xmod11(x);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends