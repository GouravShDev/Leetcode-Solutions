class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> graph[n];
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> visited(n);
        queue<int> q;
        q.push(source);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(node == destination)return true;
            visited[node] = 1;
            for(auto &adj : graph[node]){
                if(!visited[adj]){
                    q.push(adj);
                }
            }
        }
        return false;
    }
};