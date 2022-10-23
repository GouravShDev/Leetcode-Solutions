class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int  n = graph.size();
        vector<int> indegree(n);
        vector<int> revGraph[n];
        
        for(int i=0; i < n; i++){
            for(auto &nd : graph[i]){
                revGraph[nd].push_back(i);
                indegree[i]++;
            }
        }
        vector<int> ans;
        queue<int> q;
        for(int i =0; i< n ;i++){
            if(!indegree[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto &nd : revGraph[node]){
                indegree[nd]--;
                if(indegree[nd] == 0){
                    q.push(nd);
                }
            }
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};