class Node{
public:
    Node* links[26];
    bool isEnd = false;
    
    bool contains(char c){
        return links[c-'a'] != NULL;
    }
    void setLink(char c){
        links[c-'a'] = new Node();
    }
    Node* getLink(char c){
        return links[c-'a'];
    }
    void setEnd(bool f = true){
        isEnd = f;
    }
    bool getEnd(){
        return isEnd;
    }
    
};
class Solution {
public:
    Node* root;
    vector<string> ans;
     void solve(vector<vector<char>> &board , int i , int j, Node* node, string cur){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '-' || !node->contains(board[i][j])) return;
         char oldVal = board[i][j];
        board[i][j] = '-';
         node = node->getLink(oldVal);
         cur+= oldVal;
         if(node->getEnd() ){
             ans.push_back(cur);
             node->setEnd(false);
         }
     solve(board,  i + 1, j, node, cur); solve(board, i-1, j , node, cur);
            solve(board, i, j+1, node , cur);solve(board , i, j-1, node , cur);
        board[i][j] = oldVal;
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new Node();
        // insert
        for(auto &word : words){
            Node* node = root;
            for(int i =0 ; i < word.size() ; i++){
                if(!node->contains(word[i])){
                    node->setLink(word[i]);
                }
                node = node->getLink(word[i]);
            }
            node->setEnd();
        }
        for(int i =0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                solve(board, i, j, root, "");
                if(ans.size() == words.size()) return ans;
            }
        }
        
        return ans;
    }
};