//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int> steps(1e5+1, 1e8);
        steps[start] = 0;
        queue<int> q;
        q.push(start);
        int step = 0;
        while(!q.empty()){
            int size = q.size();
            step++;
            for(int i =0 ; i < size; i ++){
                int node = q.front();
                if(node == end) return steps[node];
                q.pop();
                for(auto &it : arr){
                    int cur = it * node;
                    cur %= (int) 1e5;
                    if(steps[cur] == 1e8){
                        steps[cur] = step;
                        q.push(cur);
                    }
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends