class Solution {
public:
    int solve(vector<vector<int>> &grid, int i , int j, int count){
        int n = grid.size();
        int m = grid[0].size();

        // cout<<i<<" "<<j<<endl;
        if(i == n || j == m || i < 0 || j < 0 || grid[i][j] == -1) return 0;
        if(grid[i][j] == 2){ 
            cout<<count<<endl;
            if(!count)
                return 1;
            else
                return 0;
        }
        count--;
        grid[i][j] = -1;
        int deltaXY[] = {1,0,-1,0,1};
        int ans = 0;
        for(int index = 0; index < 4; index++){
            int newRow = i + deltaXY[index];
            int newCol = j + deltaXY[index+1];
            int uqPaths =  solve(grid, newRow , newCol, count);
            ans += uqPaths;
        }
         
        grid[i][j] = 0;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int zeroCount = 1;
        int startI = -1;
        int startJ = -1;
        for(int i =0 ; i < grid.size() ;i++){
            for(int j = 0; j < grid[0].size() ; j++){
                if(grid[i][j] == 1){
                    startI = i;
                    startJ = j;
                }
                if(grid[i][j] == 0) zeroCount++;
            }
        }
        return solve(grid,startI, startJ, zeroCount);
    }
};