//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void addToAns(int i , int j , int n ,int m,  vector<vector<int>> &mat,int &ans, vector<pair<int,int>>& vec){
        
            for(auto &xy : vec){
                int x = i + xy.first;
                int y = j + xy.second;
                if(x < 0 || y < 0 || x >= n || y >= m) continue;
                ans += mat[x][y];
            }
    }
    int hopscotch(int n, int m, vector<vector<int>> mat, int ty, int i, int j)
    {
        vector<pair<int,int>> oneStepsCommon({ {-1, 0}, {1,0} , {0,1}, {0,-1} } );
        vector<pair<int,int>> twoStepsCommon({{2,0} , {-2,0} , {0,2}, {0,-2}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}  });
        
        vector<pair<int,int>> evenOneStep({{-1, -1}, {-1, 1} });
        vector<pair<int,int>> oddOneStep({ {1,-1} , {1, 1} });
        
        vector<pair<int,int>> evenTwosSteps({ {-2, -1} , {-2, 1}  });
        vector<pair<int,int>> oddTwoSteps({{ 2, -1 }, {2, 1} });
        
        int ans = 0;
        if(ty == 0){
            addToAns(i , j , n  , m , mat,ans, oneStepsCommon);
            // one step
            if(j % 2 == 0){
                // even
                addToAns(i, j ,  n , m , mat, ans, evenOneStep);
            }else{
                // odd
                addToAns(i, j ,  n , m , mat,ans,  oddOneStep);
            }
        }else{
                addToAns(i, j ,  n , m ,  mat,ans, twoStepsCommon);
            if(j % 2 == 0){
                // even
                addToAns(i, j ,  n , m , mat,ans,  oddOneStep);
                addToAns(i, j ,  n , m ,  mat, ans,evenTwosSteps);
                
            }else{
                // odd
                addToAns(i, j ,  n , m , mat,ans,  evenOneStep);
                addToAns(i, j ,  n , m ,  mat,ans, oddTwoSteps);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>ty>>i>>j;
        
        Solution ob;
        cout<<ob.hopscotch(n, m, mat, ty, i, j)<<"\n";
    }
    return 0;
}
// } Driver Code Ends