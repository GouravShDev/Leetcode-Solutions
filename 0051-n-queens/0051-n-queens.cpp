class Solution {
public:
    bool isPossible(vector<string> board, int i , int j ){
        int x = i, y = j;
        while(i >= 0 && j >= 0){
            if(board[i--][j--] == 'Q'){
                return false;
            }
        }
        while(x < board.size() && y < board.size()){
            if(board[x--][y++] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void solve(vector<string> &board, int index, vector<int> &col, vector<vector<string>> &ans){
        if(index == board.size()){
            ans.push_back(board);
            return;
        }
        for(int i = 0; i < board.size() ; i++){
            if(!col[i] && isPossible(board, index, i)){
                board[index][i] = 'Q';
                col[i] = 1;
                solve(board,  index+1, col , ans);
                col[i] = 0;
                board[index][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n , string(n,'.'));
        vector<int> colTaken(n);
        solve(board, 0 , colTaken, ans);
        return ans;
    }
};