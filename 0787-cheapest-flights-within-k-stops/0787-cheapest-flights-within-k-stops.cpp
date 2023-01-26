class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> graph[n];
        for(int i =0  ; i < flights.size() ; i++){
            int u  = flights[i][0];
            int v = flights[i][1];
            int price = flights[i][2];
            graph[u].push_back({v, price});
        }
        queue<pair<int,int>> q;
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;
        int level = 0;
        q.push({ 0, src});
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0;i < sz; i++){
                int node = q.front().second;
                int price = q.front().first;
                q.pop();
                if( k < level) continue;
                for(auto &it : graph[node]){
                    int nd = it.first;
                    int p = it.second;
                    if(p + price < prices[nd]){
                     prices[nd] = p + price;
                        q.push({p + price, nd});   
                    }
                    
                }
            }
            level++;
        }
        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};