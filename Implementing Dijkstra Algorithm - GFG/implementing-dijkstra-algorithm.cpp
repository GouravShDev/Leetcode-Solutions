//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > pq;
        vector<int> distance(V,1e8);
        distance[S] = 0;
        pq.push({0, S});
        while(!pq.empty()){
            auto weight = pq.top().first;
            auto node= pq.top().second;
            pq.pop();
            for(auto &adjNode : adj[node]){
                // cout<<adjNode[1]<<" "<<adjNode[0]<<endl;
                if(weight + adjNode[1] < distance[adjNode[0]]){
                    distance[adjNode[0]] = weight + adjNode[1];
                    //cout<<distance[adjNode[0]];
                    pq.push({distance[adjNode[0]], adjNode[0]});
                }
            }
        }
        return distance;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends