class Solution {
public:
    vector<int> parent;
    
    int find(int u){
        if( parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    void connect(int u , int v){
        u = find(u);
        v = find(v);
        if(u==v)return;
        parent[u] = v;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        parent.resize(n+1);
        iota(parent.begin(), parent.end(), 0);
        vector<pair<int,int>> graph[n+1];
        int ans = INT_MAX;
        for(auto &road : roads){
            int u = road[0];
            int v = road[1];
            int weight = road[2];
            graph[u].push_back({v, weight});
            graph[v].push_back({u, weight});
        }
        for(int i = 1;  i <= n ; i++){
            // if(!visited[i]){
                for(auto adj : graph[i]){
                    int nd = adj.first;
                    connect(i, nd);
                }
            // }
        }
        for(int i = 2;  i <= n ; i++){
            // if(!visited[i]){
            if(find(i) == find(n)){
                for(auto adj : graph[i]){
                    ans = min(ans, adj.second);
                }
            }
            // }
        }
        return ans;
    }
};