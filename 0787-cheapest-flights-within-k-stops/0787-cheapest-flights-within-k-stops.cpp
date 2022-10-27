class Solution
{
    public:
        int findCheapestPrice(int n, vector<vector < int>> &flights, int src, int dst, int k) {
            vector<pair<int,int>> graph[n];
            for(int i =0 ; i < flights.size(); i++){
                int u = flights[i][0];
                int v = flights[i][1];
                int weight = flights[i][2];
                graph[u].push_back({v, weight});
            }
            queue<pair<int, pair<int,int>>> pq;
            
            pq.push({0, {src, k}});
            vector<int> costs(n, 1e8);
            costs[src] = 0;
            while(!pq.empty()){
                int cost = pq.front().first;
                int node = pq.front().second.first;
                int steps = pq.front().second.second;
                pq.pop();
                for(auto &it : graph[node]){
                    int adjNode = it.first;
                    int adjCost = it.second;
                    
                    if(steps >= 0 && adjCost + cost < costs[adjNode]){
                        costs[adjNode] = adjCost + cost;
                        pq.push({costs[adjNode], {adjNode, steps-1}});
                    }
                }
            }
            if(costs[dst] != 1e8) return costs[dst];
            return -1;
        }
};