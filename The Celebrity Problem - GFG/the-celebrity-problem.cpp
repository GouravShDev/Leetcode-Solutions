//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        queue<int> stk;
        for(int i =0 ;i < n ;i++){
            stk.push(i);
        }
        while(stk.size() > 1){
            int p1 = stk.front(); stk.pop();
            int p2 = stk.front(); stk.pop();
            // cout<<p1<<" "<<p2<<endl;//
            // cout<<M[p1][p2]<<" "<<M[p2][p1]<<endl;
            if(!M[p1][p2] && !M[p2][p1]){
            }else if(M[p1][p2]){
                stk.push(p2);
            }else if(M[p2][p1]){
                stk.push(p1);
            }
            
        }
        if(stk.empty() )return -1;
        int pCel = stk.front();
        for(int i =0 ; i < n ; i++){
            if(i == pCel) continue;
            if(!M[i][pCel]) return -1;
            if(M[pCel][i]) return -1;
        }
        return pCel;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends