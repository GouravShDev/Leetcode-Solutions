class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> rowSet(board.size());
        vector<set<int>> colSet(board.size());
        vector<vector<set<int>>> matSet(board.size() , vector<set<int>>(board.size()));
        for(int i =0 ;i  < board.size() ; i++){
            for(int j = 0 ;j < board[0].size(); j++){
                if(board[i][j] == '.')continue;
                if(rowSet[i].count(board[i][j]) || colSet[j].count(board[i][j]) || matSet[i/3][j/3].count(board[i][j])){
                    // cout<<board[i][j]<<endl;
                    return false;
                }
                rowSet[i].insert(board[i][j]);
                colSet[j].insert(board[i][j]);
                matSet[i/3][j/3].insert(board[i][j]);
            }
        }
        return true;
    }
};