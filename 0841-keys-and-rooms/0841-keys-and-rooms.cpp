class Solution {
public:
    void dfs(vector<vector<int>> &graph, int node, vector<int> &visited){
        visited[node] = 1;
        for(auto &it : graph[node]){
            if(!visited[it]){
                dfs(graph, it, visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n);
        dfs(rooms, 0, visited);
        int sum = accumulate(visited.begin(), visited.end(), 0) ;
        return sum == n;
    }
};