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
        int ans = -1;
        for(int i =0 ; i< M.size(); i++){
            int sum = 0;
            for(int j = 0; j < M[0].size(); j++){
                sum += M[i][j];
            }
            
                if(sum == 0){
                    int flag  = 1;
                    for(int k = 0; k < M.size() ; k++){
                        if(k == i)continue;
                        if(!M[k][i]){
                            flag = 0;
                        }
                    }
                    if(flag){
                        return i;
                    }
                }
        }
        return ans;
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