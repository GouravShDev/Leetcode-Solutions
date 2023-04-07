class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n  = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            if(grid[i][0])q.push({i, 0});
            if(grid[i][m-1])q.push({i, m-1});
        }
        for(int j = 0 ;j < grid[0].size(); j++){
            if(grid[0][j]) q.push({0,j});
            if(grid[n-1][j]) q.push({n-1, j});
        }
        int delta[] = {0,1,0,-1,0};
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ;i < size; i++){
                auto [x,y] = q.front();
                q.pop();
                if(grid[x][y] != 1) continue;
                grid[x][y] = -1;
                for(int j = 0 ; j < 4; j++){
                    int newX = x + delta[j];
                    int newY = y + delta[j+1];
                    if(newX < 0 || newY < 0 || newX >= n || newY >= m || grid[newX][newY] != 1) continue;
                    q.push({newX, newY});
                }
            }
        }
        for(int i = 0; i < n ; i++){
            for(int j = 0 ; j < m ;j++){
                if(grid[i][j] == 1) ans++;
            }
        }
        return ans;
    }
};