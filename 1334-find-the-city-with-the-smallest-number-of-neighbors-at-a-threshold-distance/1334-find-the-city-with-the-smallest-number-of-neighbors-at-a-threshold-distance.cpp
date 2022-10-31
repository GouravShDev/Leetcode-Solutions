class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adjMat(n , vector<int>(n, 1e9));
        for(int i =0 ;i  < edges.size() ;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adjMat[u][v] = w;
            adjMat[v][u] = w;
        }
        for(int i = 0 ; i  < n; i++){
            adjMat[i][i] = 0;
        }
        for(int via = 0 ; via < n ; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n ; j++){
                    adjMat[i][j] = min(adjMat[i][via] + adjMat[via][j], adjMat[i][j]);
                }
            }
        }
        int ans = 0;
        int mn  =INT_MAX ;
        for(int i =n-1 ; i >= 0; i--){
            int count = 0;
            for(int j = 0; j < n; j++){
                //cout<< adjMat[i][j]<<" ";
                if(adjMat[i][j] <= distanceThreshold) count++;
            }
            //cout<<endl;
        // cout<<count;
            if(count < mn){
                ans = i;
                mn = count;
            }
        }
        return ans;
    }
};