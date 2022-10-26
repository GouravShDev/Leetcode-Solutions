//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<pair<int, int> > graph[n+1];
        for(int i = 0 ; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            graph[u].push_back({v, weight});
            graph[v].push_back({u, weight});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        pq.push({0 , 1});
        vector<int> distance(n+1, 1e8);
        distance[1] = 0;
        vector<int> parent(n+1, -1);
        while(!pq.empty()){
            auto weight = pq.top().first;
            auto node = pq.top().second;
            pq.pop();
            if(node == n){
                vector<int> ans;
                while(node != -1){
                    ans.push_back(node);
                    node = parent[node];
                }
                // for(int i = 0 ;i  < parent.size(); i++){
                //     cout<<parent[i] << " ";
                // }
                reverse(ans.begin(), ans.end());
                return ans;
            }
            for(auto &it : graph[node]){
                int nodeWeight= it.second;
                int curNode = it.first;
                if(weight + nodeWeight < distance[curNode]){
                    distance[curNode] = weight + nodeWeight;
                    parent[curNode] = node;
                    pq.push({distance[curNode] , curNode });
                }
            }
        }
        return {-1};
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends