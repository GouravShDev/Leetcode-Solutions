class Solution {
public:
    int ans = 0;
    void dfs(vector<int> graph[], int node, vector<int> &informTime, int  cur){
       
        if(graph[node].empty()) {ans = max(ans, cur); return;}
         cur += informTime[node];
        for(auto &it : graph[node]){
           dfs(graph, it, informTime, cur); 
        }
        return;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> graph[n];
        // vector<int> visited(n);
        for(int i = 0 ; i < n ; i++){
            if(manager[i] != -1){
                graph[manager[i]].push_back(i);
            }
        }
        // visited[headID]
        dfs(graph, headID, informTime, 0);
        return ans;
    }
};