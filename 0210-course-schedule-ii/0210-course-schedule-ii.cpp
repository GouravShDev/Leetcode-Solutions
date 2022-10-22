class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> topo;
        vector<int> indegree(numCourses);
        vector<int> adj[numCourses];
        for(int i=0 ; i < prerequisites.size(); i++){
            auto x = prerequisites[i];
            adj[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        queue<int> q;
        for(int i =0 ;i < numCourses; i++){
            if(!indegree[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto &adjNodes : adj[node]){
                indegree[adjNodes]--;
                if(!indegree[adjNodes]){
                    q.push(adjNodes);
                }
            }
        }
        if(topo.size() == numCourses) return topo;
        return {};
    }
};