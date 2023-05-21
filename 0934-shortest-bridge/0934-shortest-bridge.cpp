class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        bool flag = 0;
        for(int i =0 ;  i < grid.size();i++){
            
            for(int j = 0 ;  j < grid[0].size(); j++){
                if(grid[i][j]){
                    grid[i][j] = 2;
                    flag = 1;
                    q.push({i,j});
                    break;
                }
            }
            if(flag) break;
        }
        int delta[5] = {0,1,0,-1, 0};
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(int k = 0 ;  k < 4; k++){
                int newI = i + delta[k];
                int newJ = j + delta[k+1];
                if(newI < 0 || newJ < 0 || newI == grid.size() || newJ == grid[0].size() || grid[newI][newJ] !=1) continue;
                grid[newI][newJ] = 2;
                q.push({newI, newJ});
            }
        }
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size();j++){
                if(grid[i][j] == 1) {
                    // cout<<"dfa"<<endl;
                    grid[i][j] = 3;
                    q.push({i, j});
                }
            }
        }
        int ans = 0;
        while(!q.empty()){
            int sz= q.size();
            for(int x = 0 ;x < sz ; x++){
                  int i = q.front().first;
                    int j = q.front().second;
                q.pop();
                for(int k = 0 ;  k < 4; k++){
                    int newI = i + delta[k];
                    int newJ = j + delta[k+1];
                    if(newI < 0 || newJ < 0 || newI == grid.size() || newJ == grid[0].size() || grid[newI][newJ] == 3) continue;
                    if(grid[newI][newJ] == 2) return ans;
                    grid[newI][newJ] = 3;
                    q.push({newI, newJ});
                }
            }
            ans++;
        }
        return ans;
    }
};