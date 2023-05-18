class Solution {
public:
    void topoSort(vector<vector<int>> &graph, int node, vector<int> &visited, vector<int> &topo){
        visited[node] = 1;
        for(auto &it : graph[node]){
            if(visited[it]) continue;
            topoSort(graph, it, visited, topo);
        }
        topo.push_back(node);
        
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> ans;
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
        }
        vector<int> topo;
        vector<int> visited(n);
        for(int i = 0; i < n ;i++){
            if(!visited[i]){
                topoSort(graph, i , visited, topo);
            }
        }
        //for(auto &it : topo) cout<<it<<endl;
        vector<int> dfsVisited(n);
        for(int j = topo.size() -1 ; j >= 0 ; j--){
            int i = topo[j];
            if(!dfsVisited[i]){
                ans.push_back(i);
                topoSort(graph, i, dfsVisited, visited);
            }
        }
        return ans;
    }
};