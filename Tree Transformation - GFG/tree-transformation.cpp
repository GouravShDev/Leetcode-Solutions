//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int solve(int n, vector<int> p){
        set<int> s;
        int count = 0;
        for (int i = 1; i<n; i++){
            if (p[i] == 0){
                count++;
            }
            if (p[i] != 0 and p[i] != -1){
                s.insert(p[i]);
                p[i] = 0;
            }
        }
        if (count == 1){
            return max((int)s.size() - 1, 0);
        }
        return s.size();
    }
};



//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> p(N);
        for(int i = 0; i < N; i++){
            cin >> p[i];
        }

        Solution obj;
        cout << obj.solve(N, p) << "\n";
    }
}   
// } Driver Code Ends