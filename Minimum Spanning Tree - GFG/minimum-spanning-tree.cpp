//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int ans = 0;
        vector<pair<int,int>> graph[V];
        for(int i = 0;i  < V ; i++){
            for(auto &it : adj[i]){
                
            graph[i].push_back({it[0], it[1]});
            graph[it[0]].push_back({i,it[1]});
            }
            
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<int> visited(V);
        while(!pq.empty()){
            auto it = pq.top();
            int weight = it.first;
            int node = it.second;
            pq.pop();
            if(visited[node]) continue;
            visited[node] =1;
            ans += weight;
            for(auto &it : graph[node]){
                int adjNode= it.first;
                int adjWeigth = it.second;
                if(!visited[adjNode]){
                    pq.push({adjWeigth , adjNode});
                }
                
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends