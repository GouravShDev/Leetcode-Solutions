class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> distance(grid.size() , vector<int>(grid[0].size(), 1e8));
        if(grid[0][0] == 1)return -1;
        queue<pair<int,int>> q;
        distance[0][0] = 1;
        q.push({0,0});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i =-1; i < 2; i++){
                for(int j = -1; j < 2 ; j++){
                    int newRow = max(0 , min((int) grid.size()-1, row + i));
                    int newCol = max(0, min((int) grid[0].size() -1 , col + j));
                    if((newRow == row && newCol == col) || grid[newRow][newCol]) continue;
                    if(distance[row][col] + 1 < distance[newRow][newCol]){
                        distance[newRow][newCol] = distance[row][col] + 1;
                        q.push({newRow, newCol});
                    }
                }
            }
        }
        if(distance[grid.size()-1][grid[0].size()-1] == 1e8) return -1;
        return distance[grid.size()-1][grid[0].size()-1];
    }
};