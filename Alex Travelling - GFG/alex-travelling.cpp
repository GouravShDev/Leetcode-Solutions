//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        vector<pair<int,int>> graph[n];
        for(auto &flight : flights){
            int u = flight[0]-1;
            int v = flight[1]-1;
            graph[u].push_back({v, flight[2]});
        }
        vector<int> costs(n , INT_MAX);
        costs[k-1] = 0;
        queue<pair<int,int>> q;
        q.push({k-1, 0});
        while(!q.empty()){
            int node= q.front().first;
            int dis = q.front().second;
            q.pop();
            for(auto &it : graph[node]){
                int nd = it.first;
                int disNd = it.second;
                if(costs[nd] > dis + disNd){
                    costs[nd] = dis + disNd;
                    q.push({nd, costs[nd]});
                }
            }
        }
        int mx=  *max_element(costs.begin(), costs.end());
        return mx == INT_MAX ? -1 : mx;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends