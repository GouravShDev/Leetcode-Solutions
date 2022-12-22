class Solution {
public:
    int dfs(vector<int> graph[], int node, int parent, vector<int>& nodesNum){
        int numbers =  0;
        for(auto &it : graph[node]){
            if(it == parent) continue;
            numbers += dfs(graph, it, node, nodesNum);
        }
        return nodesNum[node] = 1 + numbers;
    }
    int dikjstra(vector<int> graph[], int n , int source){
        queue<int> q;
        q.push(source);
        int ans = 0;
        int level = 0;
        vector<int> visited(n);
        while(!q.empty()){
            int size = q.size();
            for(int i =0 ; i < size ; i++){
                int node = q.front();
                visited[node] = 1;
                q.pop();
                for(auto &it : graph[node]){
                    if(visited[it]) continue;
                    q.push(it);
                }
                // cout<<level<<endl;
                ans += level;
            }
            level++;
        }
        return ans;
    }
    void solve(vector<int> graph[], int node, int parent, int n, vector<int> &nodesNum,  vector<int> &ans){
        // cout<<node<<endl;
        ans[node] = ans[parent] - (nodesNum[node] ) + (n - nodesNum[node]);
        for(auto &it : graph[node]){
            if(it == parent)continue;
            solve(graph, it, node, n , nodesNum, ans);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> graph[n];
        vector<int> nodesNum(n);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(graph, 0, 0, nodesNum);
        // for(auto &it : nodesNum){
        //     cout<<it<<" ";
        // }
        int rootAns = dikjstra(graph, n, 0);
        vector<int> ans(n);
        ans[0] = rootAns;
        for(auto &it : graph[0]){
            solve(graph, it , 0 , n, nodesNum, ans);
        }
        return ans;
    }
};