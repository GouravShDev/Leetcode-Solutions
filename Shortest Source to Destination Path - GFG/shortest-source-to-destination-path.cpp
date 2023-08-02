//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        int ans = 0;
        queue<pair<int,int>> q;
        q.push({0,0});
        A[0][0] =2;
        int delta[5] = {0,1,0,-1,0};
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                auto ij = q.front();
                q.pop();
                if(ij.first == X && ij.second == Y ) return ans;
                for(int j = 0 ;j < 4; j ++){
                    int newI = ij.first + delta[j];
                    int newJ = ij.second + delta[j+1];
                 if(newI < 0 || newJ < 0|| newI >= N || newJ >= M || A[newI][newJ] != 1) continue;   
    
                A[newI][newJ] = 2;
                q.push({newI, newJ});
                }
            }
            ans++;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends