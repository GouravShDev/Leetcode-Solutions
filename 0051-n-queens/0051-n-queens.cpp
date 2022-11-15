class Solution {
public:
    bool isPossible(vector<vector<int>> board, int i , int j ){
        int x = i, y = j;
        while(i >= 0 && j >= 0){
            if(board[i--][j--]){
                return false;
            }
        }
        while(x < board.size() && y < board.size()){
            if(board[x--][y++]){
                return false;
            }
        }
        return true;
    }
    void solve(vector<vector<int>> &board, int index, vector<int> &col, vector<vector<string>> &ans){
        if(index == board.size()){
            vector<string> curVec;
            for(int i = 0; i < board.size() ; i++){
                string cur = "";
                for(int j = 0; j < board.size() ; j++){
                    if(board[i][j]){
                        cur += 'Q';
                    }else{
                        cur += '.';
                    }
                }
                curVec.push_back(cur);
                
            }
            ans.push_back(curVec);
            return;
        }
        for(int i = 0; i < board.size() ; i++){
            if(!col[i] && isPossible(board, index, i)){
                board[index][i] = 1;
                col[i] = 1;
                solve(board,  index+1, col , ans);
                col[i] = 0;
                board[index][i] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<int>> board(n , vector<int>(n));
        vector<int> colTaken(n);
        solve(board, 0 , colTaken, ans);
        return ans;
    }
};