class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        stack<int> stk;
    
        for(int i = 0 ; i <n ; i++){
            stk.push(i);
        }
        vector<vector<int>> mat(n,  vector<int> ( n));
        for(int i =0 ;i < trust.size() ;i++){
            mat[trust[i][0]-1][trust[i][1]-1] = 1;
        }
        while(stk.size() > 1){
            int u = stk.top(); stk.pop();
            int v = stk.top(); stk.pop();
            if(mat[u][v] && mat[v][u]){
                continue;
            }else if(mat[u][v]){
                stk.push(v);
            }else if(mat[v][u]){
                stk.push(u);
            }
        }
        if(stk.empty()) return -1;
        for(int i = 0 ;i < n ; i++){
            if(i == stk.top() )continue;
            if(mat[stk.top()][i]) return -1;
        }
        return stk.top()+1;
    }
};