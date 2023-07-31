//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
       vector<int> ans;
       vector<int> visited(V);
       queue<int> q;
       q.push(0);
       while(!q.empty()){
           int sz = q.size();
           for(int i = 0 ;i < sz; i++){
               int node = q.front();
               q.pop();
               if(visited[node]) continue;
                   ans.push_back(node);
               visited[node] = 1;
               for(auto &adjNode : adj[node]){
               if(visited[adjNode]) continue;
                   q.push(adjNode);
               }
           }
       }
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends