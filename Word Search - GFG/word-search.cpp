//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int delta[5] = {0,1,0,-1,0};
    bool solve(vector<vector<char>> &board, int i , int j , string word, int index){
        if(index == word.size()) return true;
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) return false;
        char curChar = board[i][j];
        board[i][j] = '#';
        for(int d = 0 ; d < 5 ; d++){
            int newI = i + delta[d];
            int newJ = j + delta[d+1];
            if(solve(board, newI, newJ, word, index+1)) return true;
        }
        board[i][j] = curChar;
        return false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        for(int i= 0 ;i < board.size() ; i++){
            for(int j = 0 ;j < board[0].size(); j++){
                if(solve(board, i ,j , word, 0)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends