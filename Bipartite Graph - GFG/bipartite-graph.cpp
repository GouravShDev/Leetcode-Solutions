//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool checkBP(vector<int> adj[], int node, int lastColor, vector<int> &visited ){
        int color = (lastColor == 1) ? 2 : 1;
        visited[node] = color;
        for(auto &nd : adj[node]){
            if(!visited[nd]){
                visited[nd] = color;
                if(!checkBP(adj, nd, color, visited))return false;
            }
            else if(visited[nd] == color) return false;
        }
        return true;
        
    }
    bool dfs(vector<int> graph[], int node, vector<int>& visited, int lcolor)
        {
            visited[node] = lcolor;
            for (auto &adj: graph[node])
            {
                if (!visited[adj])
                {
                    if (!dfs(graph, adj, visited, lcolor == 2 ? 1 : 2))
                        {
                            return false;
                        }
                    
                    
                }else if (visited[adj] == lcolor)
                    {
                        return false;
                    }
            }
            return true;
        }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> visited(V);
	    for(int i = 0; i < V; i++){
	        if(!visited[i]){
	            if(!dfs(adj, i, visited,1))return false;
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends