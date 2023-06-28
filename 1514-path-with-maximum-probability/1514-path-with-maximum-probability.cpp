class Solution {
public:
    // double solve(vector<pair<int,double>> graph[], int node, int parent, vector<int> &visited, int target){
    //     double ans = 0;
    //     if(node == target){
    //         ans=1;
    //     }
    //     visited[node] = 1;
    //     for(auto &it: graph[node]){
    //         if(visited[it.first]) continue;
    //         double cur = it.second;
    //         double dfs = solve(graph, it.first, visited, target);
    //         //cout<<cur<<" "<<dfs<<endl;
    //         ans = max(ans,  cur * dfs);
    //     }
    //     // cout<<ans<<endl;
    //     return ans;
    // }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> graph[n];
        for(int i = 0 ;i < edges.size();i++){
            auto edge = edges[i];
            graph[edge[0]].push_back({edge[1], succProb[i]});
            graph[edge[1]].push_back({edge[0], succProb[i]});
        }
        vector<double> probability(n, 0);
        priority_queue<pair<double,int>> pq;
        double ans = 0;
        pq.push({1, start});
        probability[start] = 1;
        while(!pq.empty()){
            auto prob = pq.top().first;
            auto node = pq.top().second;
            pq.pop();
         //   cout<<prob<<endl;
            if(node == end){
                return prob;
            }
            for(auto &it: graph[node]){
                auto u = it.first;
                auto weight = it.second;
                if(probability[u] >= (weight * prob)) continue;
                probability[u] = weight * prob;
                pq.push({probability[u], u});
            }
        }
        return ans ;
    }
};