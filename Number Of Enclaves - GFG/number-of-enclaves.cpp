//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class UnionFind{
    public:
    vector<int> parent;
    int n;
    UnionFind(int size){
        n = size;
        parent.resize( n);
        iota(parent.begin(), parent.end(), 0);
    }
    int findParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    void connect(int u , int v){
        u = findParent(u);
        v = findParent(v);
        if(u == v )return ;
        parent[v] = u;
        n--;
    }
};
class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        UnionFind uf(n* m + 1);
        int zeroCount = 0;
        int delta[5] = {0,1,0,-1,0};
        for(int i = 0;  i < n ; i++){
            for(int j = 0; j< m ; j++){
                if(grid[i][j] == 0){
                    zeroCount++;
                    continue;
                }
                for(int k = 0 ; k < 4; k++){
                    int newI = i + delta[k];
                    int newJ = j + delta[k+1];
                    if(newI < 0 || newJ < 0 || newI >= n || newJ >= m || grid[newI][newJ] == 0) continue;
                    int x = (i * m) + j;
                    int y = (newI * m) + newJ;
                    uf.connect(x , y);
                }
            }
        }
        for(int i = 0; i < n ; i++){
            if(grid[i][0] == 1) uf.connect(n*m , (i * m ));
            if(grid[i][m-1] == 1) uf.connect(n *m , (i * m) + m-1);
        }
        for(int j = 0; j < m ; j++){
            if(grid[0][j] == 1) uf.connect(n * m , j);
            if(grid[n-1][j] == 1) uf.connect(n * m, (n-1) * m + j);
        }
        int ans = 0;
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ;j < m; j++){
                if(grid[i][j] == 0) continue;
                if(uf.findParent((i * m) + j) != uf.findParent(n * m) ) ans++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends