class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<pair<pair<int,int>, int>> q;
        q.push({{0,0}, k});
        int steps = 0;
        int delx[] = {0,1,-1,0};
        int dely[] = {1,0,0,-1};
        vector<vector<int>> visited(grid.size() , vector<int>(grid[0].size(), -1));
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size ; i++){
                int row = q.front().first.first;
                int col = q.front().first.second;
                int obs = q.front().second;
                q.pop();
                if(row == grid.size()-1 && col == grid[0].size()-1) return steps;
                for(int index = 0; index < 4; index++){
                    int newRow = row + delx[index];
                    int newCol = col + dely[index];
                    if(newRow < 0 || newCol < 0 || newRow >= grid.size() || newCol >= grid[0].size()) continue;
                    if(visited[newRow][newCol] != -1 && visited[newRow][newCol] >= obs){
                        continue;
                    }
                        if(grid[newRow][newCol] && obs > 0){
                            q.push({{newRow, newCol}, obs-1});
                            
                    visited[newRow][newCol] = obs-1;
                        }else if(grid[newRow][newCol] == 0 ) {
                            q.push({{newRow, newCol}, obs});
                            
                    visited[newRow][newCol] = obs;
                        }
                    
                }
            }
            steps++;
        }
        return -1;
    }
};