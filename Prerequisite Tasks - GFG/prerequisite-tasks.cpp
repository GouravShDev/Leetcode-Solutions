//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int node, vector<int> adj[], stack<int> &stk, vector<int> &visited, vector<int> &dfsVisited){
        visited[node] = 1;
        dfsVisited[node] = 1;
        for(auto &it : adj[node]){
            if(!visited[it]){
                if(dfs(it, adj , stk, visited,dfsVisited)) return true;
            }else if(dfsVisited[it]){
                return true;
            }
        }
        stk.push(node);
        dfsVisited[node] = 0;
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    vector<int> adj[N];
	    for(int i=0 ;i < pre.size() ;i++){
	        int u = pre[i].second;
	        int v = pre[i].first;
	        adj[v].push_back(u);
	    }
	    vector<int> visited(N);
	    vector<int> dfsVisited(N);
	    stack<int> stk;
	    for(int i =0 ;i < N ; i++){
	        if(!visited[i]){
	            (dfs(i , adj,stk, visited, dfsVisited)) ;
	        }
	    }
	    return stk.size() == N;
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