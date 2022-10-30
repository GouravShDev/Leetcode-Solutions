//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&distance){
	    int n = distance.size();
	    for(int i = 0; i < distance.size()  ; i++){
	        for(int j = 0; j < distance[0].size(); j++){
	            if(distance[i][j] == -1)
	                distance[i][j] = 1e9;
	        }
	    }
        for(int via = 0; via < n; via++ ){
    	    for(int src = 0; src < distance.size() ; src++){
    	        for(int dest = 0; dest < distance[0].size() ; dest++){
    	            distance[src][dest] = min(distance[src][via] + distance[via][dest] , distance[src][dest]);
    	        }
    	    }
        }
        for(int i = 0; i < distance.size()  ; i++){
	        for(int j = 0; j < distance[0].size(); j++){
	            if(distance[i][j] == 1e9)
	                distance[i][j] = -1;
	        }
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends