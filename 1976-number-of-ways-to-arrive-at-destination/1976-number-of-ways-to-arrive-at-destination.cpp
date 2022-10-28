class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long> times(n, LONG_LONG_MAX);
        vector<long long> ways(n, 0);
        vector<pair<int,long long>> graph[n];
        for(int i =0 ; i < roads.size() ; i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int weight = roads[i][2];
            graph[u].push_back({v, weight});
            graph[v].push_back({u, weight});
        }
        times[0] = 0;
        int ans = 0;
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>> > pq;
        pq.push({0, 0});
        long long MOD = 1e9+7;
        ways[0] =1 ;
        while(!pq.empty()){
            int node = pq.top().second;
            long long weight= pq.top().first;
           // cout<<node<<endl;
            pq.pop();
            if(node== n-1){
                return ways[node];
            }
            if(weight > times[n-1]) break;
            for(auto &it : graph[node]){
                long long adjNode = it.first;
                long long adjWeight = it.second;
                // long long x = ;
                // if(x >= MOD) x %= MOD;
                if(adjWeight + weight <= times[adjNode]){
                    if( adjWeight + weight== times[adjNode]){
                        ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                    }else{
                        ways[adjNode] = ways[node];
                        times[adjNode] = (adjWeight + weight) ;
                        pq.push({times[adjNode], adjNode});
                    }
                }
            }
        }
        
        return ans;
    }
};