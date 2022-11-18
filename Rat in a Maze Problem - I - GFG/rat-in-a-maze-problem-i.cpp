//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(vector<vector<int>> &m, int i ,int j, string &cur, vector<string> &ans){
        int n  = m.size();
         if(i < 0 || j < 0 || i >= n || j >= n || m[i][j] == 0){
            return;
        }
        if(i == n-1 && j == n-1 ){
            ans.push_back(cur);
            return;
        }
       m[i][j] = 0;
        cur.push_back('D');
        solve(m , i+1, j , cur, ans);
        cur.pop_back();
        
        cur.push_back('U');
        solve(m , i-1, j , cur, ans);
        cur.pop_back();
        
        cur.push_back('R');
        solve(m , i, j+1 , cur, ans);
        cur.pop_back();
        
        cur.push_back('L');
        solve(m , i, j-1 , cur, ans);
        cur.pop_back();
        
        m[i][j]= 1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(m[0][0] != 1 || m[n-1][n-1] != 1) return {};
        vector<string> ans;
        string cur;
        solve(m , 0 , 0 , cur, ans);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends