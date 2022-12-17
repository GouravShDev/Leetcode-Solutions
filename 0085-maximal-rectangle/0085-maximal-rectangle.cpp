class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0 ;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<pair<int,int> >> leftAndRight(n, vector<pair<int,int>>(m , {-1, m}));
        vector<int> heights(m);
        for(int i =0 ; i < n ; i++){
            stack<int> stk;
            for(int j = 0 ; j< m ; j++){
                if(matrix[i][j] == '1')
                    heights[j] += matrix[i][j] - '0';
                else{
                    heights[j] = 0;
                }
                // cout<<heights[j]<<" ";
                while(!stk.empty() && heights[stk.top()] > heights[j]){
                    leftAndRight[i][stk.top()].second = j;
                    stk.pop();
                }
                stk.push(j);
            }
            // cout<<endl;
            for(int j = m-1; j >= 0 ; j--){
                while(!stk.empty() && heights[stk.top()] > heights[j]){
                    leftAndRight[i][stk.top()].first = j;
                    stk.pop();
                }
                stk.push(j);
            }
            for(int j  = 0 ; j < m ; j++){
                ans = max(ans, heights[j] * (leftAndRight[i][j].second -1 - leftAndRight[i][j].first));
            }
        }
        return ans;
    }
};