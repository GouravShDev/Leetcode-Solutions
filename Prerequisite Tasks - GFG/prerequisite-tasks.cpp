//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int node, vector<int> adj[], vector<int> &dfsVisited, vector<int> &visited){
        visited[node] = 1;
        dfsVisited[node] = 1;
        for(auto &it : adj[node]){
            if(!visited[it]){
                if(dfs(it, adj , dfsVisited, visited)) return true;
            }else if(dfsVisited[it] ){
                return true;
            }
        }
        dfsVisited[node] = 0;
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    vector<int> adj[N];
	    for(int i=0 ;i < pre.size() ;i++){
	        int u = pre[i].second;
	        int v = pre[i].first;
	        adj[u].push_back(v);
	    }
	    vector<int> visited(N);
	    vector<int> dfsVisited(N);
	    for(int i =0 ;i < N ; i++){
	        if(!visited[i]){
	            if(dfs(i , adj, dfsVisited, visited)){
	                //cout<<i<<endl;
	                return false;
	            }
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
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends