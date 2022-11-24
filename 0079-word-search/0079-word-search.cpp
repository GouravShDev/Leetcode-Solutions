class Solution {
public:
    bool solve(vector<vector<char>> &board, string word ,int index, int i , int j){
        if(index >= word.size()) return true;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ) return false;
        if(word[index] != board[i][j]) return false;
        board[i][j] = '-';
        bool isPoss = solve(board, word, index+1, i + 1, j ) || solve(board, word, index+1, i-1, j) ||
            solve(board, word, index+1, i, j+1) || solve(board , word, index+1 , i, j-1);
        board[i][j] = word[index];
        return isPoss;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i =0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                if(solve(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
};