class Solution {
public:
     bool dfs(vector<vector<int>> &graph, int node,vector<int> &colors,  int prevColor){
         int curColor = prevColor ? 0 : 1;
         colors[node] = curColor;
         for(auto &adjNode : graph[node]){
             if(colors[adjNode] == curColor) return false;
             if(colors[adjNode] != -1) continue;
             if(!dfs(graph , adjNode, colors, curColor)) return false;
         }
         return true;
         
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);
        for(int i = 0 ;i < n ; i++){
            if(colors[i] != -1) continue;
            if(!dfs(graph, i, colors, 0)) return false;
        }
        return true;
        
    }
};