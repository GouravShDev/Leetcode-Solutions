class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;
        for(int i =0 ;i  < board.size() ; i++){
            for(int j = 0 ;j < board[0].size(); j++){
                if(board[i][j] == '.')continue;
                string r = to_string(board[i][j]) + " row " + to_string(i);
                string c = to_string(board[i][j]) + " col " + to_string(j);
                string rc = to_string(board[i][j]) + " block " + to_string(i/3)  + to_string(j / 3);
                if(st.count(r) || st.count(c) || st.count(rc)){
                    // cout<<board[i][j]<<endl;
                    return false;
                }
                st.insert(r);
                st.insert(c);
                st.insert(rc);
            }
        }
        return true;
    }
};