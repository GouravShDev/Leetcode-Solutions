class Solution {
public:
    bool solve(vector<vector<char>> &board, int i , int j , vector<set<char>> &rowSet,  vector<set<char>> &colSet , vector<vector<set<char>>> &boardSet){
        if(i == board.size()) return true;
        int n = board.size();
        if(board[i][j] == '.'){
            for(char num = '1' ; num  <= '9' ; num++){
                if(rowSet[i].find(num) == rowSet[i].end() && colSet[j].find(num) == colSet[j].end()&& boardSet[i/3][j/3].find(num) == boardSet[i/3][j/3].end()){
                    board[i][j] = num;
                    rowSet[i].insert(num);
                    colSet[j].insert(num);
                    boardSet[i/3][j/3].insert(num);
                    if(solve(board, i+((j + 1)/n) , (j+1)%n, rowSet, colSet, boardSet )){
                        return true;
                    }
                    board[i][j] = '.';
                    rowSet[i].erase(num);
                    colSet[j].erase(num);
                    boardSet[i/3][j/3].erase(num);
                }
            }
            return false;
        }
        
        return solve(board, i+((j + 1)/n) , (j+1)%n, rowSet, colSet, boardSet );
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<set<char>> rowSet(board.size());
        vector<set<char>> colSet(board.size());
        vector<vector<set<char>>> boardSet(3, vector<set<char>>(3));
        for(int i = 0; i < board.size() ; i++){
            for(int j =0 ; j < board.size(); j++){
                if(board[i][j] != '.'){
                    rowSet[i].insert(board[i][j]);
                    colSet[j].insert(board[i][j]);
                    boardSet[i/3][j/3].insert(board[i][j]);
                }
            }
        }
        solve(board,0, 0, rowSet, colSet, boardSet);
        return;
    }
};