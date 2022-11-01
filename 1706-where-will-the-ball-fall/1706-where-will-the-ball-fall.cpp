class Solution {
public:
    int solve(vector<vector<int>>& grid, int col , int row){
        if(row == grid.size()){return col;}
        if(grid[row][col] == -1){
            if(col - 1 >= 0 && grid[row][col-1] == -1){
                return solve(grid, col -1, row+1 );
            }else{
                return -1;
            }
        }else{
            if(col + 1 < grid[0].size() && grid[row][col+1] == 1){
                return solve(grid, col +1, row+1 );
            }else{
                return -1;
            }
            
        }
        return -1;
        
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size() , -1);
       for(int j = 0 ;j  < grid[0].size() ;j++) {
           ans[j] = solve(grid , j, 0);
       }
        return ans;
    }
};
// 100 * 100 * 100 
