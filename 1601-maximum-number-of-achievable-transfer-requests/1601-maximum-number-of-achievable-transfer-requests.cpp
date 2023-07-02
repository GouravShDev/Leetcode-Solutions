class Solution {
public:
    // int ans =0 ;
    int solve(vector<vector<int>> &request, int index, vector<int> &indegree){
        if(index == request.size()){
            for(int i = 0; i < indegree.size();i++){
                if(indegree[i] != 0 ) return INT_MIN;
            }
            return 0;
        }
        int ans = INT_MIN;
        // taking
        --indegree[request[index][0]];
        ++indegree[request[index][1]];
        ans = max(ans, 1 + solve(request, index+1, indegree));
        ++indegree[request[index][0]];
        --indegree[request[index][1]];
        // not taking
        ans = max(ans ,  solve(request, index+1, indegree));
        return ans;
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> indegree(n, 0);
        return solve(requests, 0, indegree);
        // return ans;
    }
};