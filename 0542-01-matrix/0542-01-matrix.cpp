class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), INT_MAX));
        
        queue<pair<int,int>> q;
        for(int i = 0 ;i < mat.size(); i++){
            for(int j = 0 ;j < mat[0].size(); j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int dis = 0;
        int delta[5] = {0,1,0,-1,0};
        while(!q.empty()){
            dis++;
            int sz = q.size();
            for(int i = 0 ; i< sz ; i++){
                auto xy = q.front();
                q.pop();
                for(int k = 0 ; k < 4; k++){
                    int newX = xy.first + delta[k];
                    int newY = xy.second + delta[k+1];
                    if(newX < 0 || newY < 0 || newX == mat.size() || newY == mat[0].size() || mat[newX][newY] == 0 || dis >= ans[newX][newY]) continue;
                    ans[newX][newY] = dis;
                    q.push({newX, newY});
                    
                }
            }
            
        }
        return ans;
    }
};