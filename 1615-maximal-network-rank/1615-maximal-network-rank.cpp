class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> inDegree(n);
        vector<vector<int>> isConnected(n, vector<int>(n));
        for(auto &road : roads){
            int u = road[0];
            int v = road[1];
            inDegree[u]++;
            inDegree[v]++;
            isConnected[u][v] = 1;
            isConnected[v][u] = 1;
        }
        int ans = 0;
        for(int i = 0; i< n; i++){
            for(int j = i+1; j < n ;j++){
                ans = max(ans, inDegree[i] + inDegree[j] - (isConnected[i][j]));
            }
        }
        return ans;
    }
};