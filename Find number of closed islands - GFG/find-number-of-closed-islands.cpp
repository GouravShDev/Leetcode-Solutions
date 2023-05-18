//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class UnionFind{
    private:
        vector<int> parents;
        int totalNumber;
        int components;
    public:
        UnionFind(int n){
            totalNumber = n;
            components = n;
            parents.resize(totalNumber);
            iota(parents.begin(), parents.end(), 0);
        }
        int findParent(int p){
            if(p == parents[p]) return p;
            return parents[p] = findParent(parents[p]);
        }
        void connect(int u , int v){
            int parentU = findParent(u);
            int parentV = findParent(v);
            if(parentU == parentV) return;
            components--;
            parents[parentV] = parentU;
        }
        int getComponents(){
            return components;
        }
};
class Solution {
    public:
    int delta[5] = {0,1,0,-1,0};
    void connect(UnionFind &uf, int i, int j,vector<vector<int>> &matrix){
        if(!matrix[i][j]) return ;
        for(int k = 0 ; k < 4 ; k ++){
            int newX = i + delta[k];
            int newY = j + delta[k+1];
            if(newX < 0 || newY < 0 || newX >= matrix.size()|| newY >= matrix[0].size() || !matrix[newX][newY]){
                continue;
            }
            uf.connect(i * matrix[0].size() + j, newX * matrix[0].size() + newY );
        }
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        int zeroCount = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        UnionFind uf(n * m + 1);
        for(int i = 0 ; i < matrix.size(); i++){
            if(matrix[i][0]) uf.connect(m *n , i * m  + 0);
            if(matrix[i][m-1]) uf.connect(m * n ,i * m + m-1);
        }
        for(int j = 0; j < matrix[0].size(); j++){
            if(matrix[0][j]) uf.connect(m * n , j);
            if(matrix[n-1][j]) uf.connect(m * n,(n-1) * m + j);
        }
        for(int i = 0 ;i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                connect(uf, i , j, matrix);
                if(!matrix[i][j]) zeroCount++;
            }
        }
        //cout<<uf.getComponents()<<endl;
        return uf.getComponents() - zeroCount-1;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends