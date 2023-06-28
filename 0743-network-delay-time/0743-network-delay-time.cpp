class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > pq;
        vector<pair<int,int>> graph[n];
        for(auto &time : times){
            graph[time[0]-1].push_back({time[1]-1, time[2]});
        }
        int time = -1;
        vector<int> distance(n, INT_MAX);
        pq.push({0, k-1});
        distance[k-1] = 0;
        while(!pq.empty()){
                auto node = pq.top().second;
                auto dis = pq.top().first;
                pq.pop();
                for(auto &it : graph[node]){
                    int v = it.first;
                    int weight = it.second;
                    if(distance[v] <= weight + dis) continue;
                    distance[v] = weight + dis;
                    pq.push({weight + dis, v});
                }
        }
        int ans = 0;
        for(auto &it: distance){
            if(it==INT_MAX) return-1;
            ans = max(ans, it);
        }
        return ans;
    }
};