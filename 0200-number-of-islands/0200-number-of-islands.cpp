class Solution {
public:
    void dfs(vector<vector<char>> &grid, int row , int col , vector<vector<int>> &visited){
        visited[row][col] = 1;
        int delta[] = {0, 1, 0, -1 ,0 };
        for(int i  = 0 ; i < 4; i++){
            int newRow = row + delta[i];
            int newCol = col + delta[i+1];
            if(newRow < 0 || newCol < 0 || newRow >= grid.size() || newCol >= grid[0].size()) continue;
            if(!visited[newRow][newCol] && grid[newRow][newCol] == '1')
                dfs(grid, newRow, newCol , visited);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n , vector<int>(m));
        int ans =0 ;
        for(int i =0 ; i< n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!visited[i][j]  && grid[i][j] == '1'){
                    ans++;
                    dfs(grid, i , j , visited);
                }
            }
        }
        return ans;
    }
};