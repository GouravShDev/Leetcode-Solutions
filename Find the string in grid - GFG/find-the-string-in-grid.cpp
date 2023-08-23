//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
// -1 - unset
//  0 - horizontally left
//  1 - horizontally right
//  2 - vertically up
//  3 - vertically down
//  4 - leftUp
//  5 - rightup
//  6 - rightDown
//  7 - leftDown

    bool solve(vector<vector<char>> &grid,int direction , string &word, int i , int j , int index){
        if(index == word.size()){
           //cout<< i <<":"<< j << endl;
            return true;
        }
        if( i < 0 || j < 0 || i == grid.size() || j == grid[0].size()){
            return false;
        }
        if(grid[i][j] != word[index]) return false;
        index++;
        // leftward = -1, -1 || 0 , -1 || 1 , -1
        if(direction == -1 || direction == 1){
            if(solve(grid, 1 , word, i-1 , j-1 , index)) return true;
        }
        
        if(direction == -1 || direction == 2){
            if(solve(grid, 2 , word, i , j-1 , index)) return true;
        }
        
        if(direction == -1 || direction == 3){
            if(solve(grid, 3 , word, i+1 , j-1, index)) return true;
            
        }
        // rightward = -1,1 || 0, 1 || 1 , 1
            if(direction == -1 || direction == 4){
                if(solve(grid, 4 , word, i-1, j+1 , index)) return true;
            }
            
            if(direction == -1 || direction == 5){
                if(solve(grid, 5 , word, i , j+1 , index)) return true;
            }
            
            if(direction == -1 || direction == 6){
                if(solve(grid, 6 , word, i+1, j+1, index)) return true;
            }
            
        
        // upDown = -1, 0 || 1 , 0

            if(direction == -1 || direction == 7){
                if(solve(grid, 7 , word, i -1 , j , index)) return true;
            }
            
            if(direction == -1 || direction == 8){
                 if(solve(grid, 8 , word, i + 1 , j , index)) return true;
            }
            return false;

    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    vector<vector<int>> ans;
	    
	    for(int i =0 ; i< grid.size() ; i++){
	        for(int j = 0 ;j < grid[0].size();j++){
	            if(solve(grid, -1, word, i,  j , 0)){
	                ans.push_back({i,j});
	            }
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends