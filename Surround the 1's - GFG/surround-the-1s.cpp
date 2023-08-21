//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        int count = 0;
        for(int i = 0; i <matrix.size(); i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
                if(matrix[i][j] == 0)continue;
                int zeroCount = 0;
                for(int k = -1; k < 2; k++){
                    for(int l = -1; l < 2 ; l++){
                        int newI = i + k;
                        int newJ = j + l;
                        if(newI < 0 || newJ < 0) continue;
                        if(newI == matrix.size() || newJ == matrix[0].size()) continue;
                        if(matrix[newI][newJ] == 1) continue;
                        zeroCount++;
                    }
                }
                if(zeroCount == 0) continue;
                if(zeroCount % 2 ==0 )count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends