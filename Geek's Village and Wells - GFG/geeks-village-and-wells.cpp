//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        vector<vector<int>> ans(n , vector<int>(m, 0));
        queue<pair<int,int>> q;
        for(int i= 0 ; i< n ;i++){
            for(int j = 0;j  < m ;j++){
                if(c[i][j] == 'W'){
                    q.push({i,j});
                    c[i][j] = 'N';
                }
                else if(c[i][j] == 'H'){
                    
                    ans[i][j] = -1;
                }
            }
        }
        int distance = 0;
        int delta[] = {0,1,0,-1,0};
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0 ;i < sz; i++){
                auto xy = q.front();
                q.pop();
                if(ans[xy.first][xy.second] == -1) ans[xy.first][xy.second] = 2 * distance;
                for(int j= 0; j < 4; j++){
                    int newX = xy.first + delta[j];
                    int newY = xy.second + delta[j+1];
                    if(newX < 0 || newY < 0 || newX >= n || newY >= m || !(c[newX][newY] == 'H' || c[newX][newY] == '.' )) continue;
                    q.push({newX, newY});
                    c[newX][newY] = 'N';
                }
            }
            distance++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends