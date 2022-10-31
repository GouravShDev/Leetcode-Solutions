class Solution {
public:
    vector<int> dijkstraAlgo(vector<pair<int,int> > graph[], int V, int src){
        vector<int> distance(V, 1e9);
        priority_queue<pair<int,int> , vector<pair<int,int> >, greater<pair<int,int> > > pq;
        pq.push({0, src});
        distance[src] = 0;
        while(!pq.empty()){
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto &it : graph[node]){
                int adjWeight = it.second;
                int adjNode = it.first;
                if( adjWeight + weight < distance[adjNode]){
                    distance[adjNode] = adjWeight + weight;
                    pq.push({distance[adjNode] , adjNode});
                }
            }
        }
        return distance;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>> graph[n];
        for(auto edge : edges){
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        
        int ans = 0;
        int mn = INT_MAX;
        for(int i = n-1; i >= 0; i --){
            vector<int> dis = dijkstraAlgo(graph, n , i);
            int count = 0;
            for(auto &d : dis){
                // cout<<d<<" ";
                if( d <=distanceThreshold){
                    count ++;
                }
            }
            // cout<<endl;
            if(count < mn){
                ans = i;
                mn = count;
            }
        }
        return ans;
    }
};