class Solution {
public:
    void dfs(vector<vector<int>> &graph, int node, vector<int>& visited, vector<int> &path, vector<vector<int>> &ans){
        path.push_back(node);
        visited[node] = 1;
        if(node == graph.size()-1){
            ans.push_back(path);
        visited[node] = 0;
        path.pop_back();
            return ;
        }
        for(auto &it : graph[node]){
            if(!visited[it]){
                dfs(graph, it, visited, path, ans);
            }
        }
        visited[node] = 0;
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n);
        vector<vector<int>> ans;
        vector<int> path;
        // for(int i =0 ;i < n ; i++){
            // if(!visited[i]){
                dfs(graph, 0, visited, path, ans);
            // }
        // }
        return ans;
    }
};