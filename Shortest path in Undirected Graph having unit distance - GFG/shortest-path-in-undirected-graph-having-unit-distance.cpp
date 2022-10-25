//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> graph[N];
        for(int i =0 ; i < edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> dis(N, 1e8);
        dis[src] = 0;
        queue<pair<int,int>> q;
        q.push({src, 0});
        while(!q.empty()){
            int node = q.front().first;
            int weight = q.front().second + 1;
            q.pop();
            for(auto nd : graph[node]){
                if( weight < dis[nd]){
                    dis[nd]=weight;
                    q.push({nd, weight});
                }
            }
        }
        for(int i =0 ; i < dis.size() ;i ++){
            if(dis[i] == 1e8) dis[i] = -1;
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends