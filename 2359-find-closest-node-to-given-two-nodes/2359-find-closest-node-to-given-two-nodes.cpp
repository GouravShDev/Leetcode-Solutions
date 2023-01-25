class Solution {
public:
    void dfs(vector<int> &edges, int node, int dis, vector<int> &visited){
        if(node == -1 || visited[node] != INT_MAX)return;
        visited[node] = dis;
        dfs(edges, edges[node], dis + 1, visited);
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        if(node1== node2) return node1;
        vector<int> visited1(n, INT_MAX);
        vector<int> visited2(n, INT_MAX);
        dfs(edges, node1, 0, visited1);
        dfs(edges, node2, 0, visited2);
        int ans = -1;
        int mxDis = INT_MAX;
        for(int i =0 ;i < n ;i++){
            int mxD = max(visited1[i] , visited2[i]);
            if(mxD < mxDis){
                mxDis = mxD;
                ans = i;
            }
        }
        return ans;
    }
};