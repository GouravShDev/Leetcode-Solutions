class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size()-1;
        int m = maze[0].size()-1;
        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        int level = 0;
        int delta[] = {0,1,0,-1,0};
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ;i < size; i++){
                auto [row, col] = q.front();
                if(row == 0 || row == n || col == 0 || col == m){
                    if(!(row == entrance[0] && col == entrance[1])){
                        return level;
                    }
                }
                q.pop();
                for(int j = 0; j < 4 ; j++){
                    int newRow = row + delta[j];
                    int newCol = col + delta[j+1];
                    if(newRow >= 0 && newCol >= 0 && newRow <= n && newCol <= m && maze[newRow][newCol] == '.'){
                        maze[newRow][newCol] = '+';
                        q.push({newRow, newCol});
                    }
                }
            }
            level++;
        }
        return -1;
    }
};