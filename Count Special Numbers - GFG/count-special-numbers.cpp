//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        map<int,int> mp;
        for(auto &it : arr) mp[it]++;
        int ans = 0;
        for(int i = 0 ; i < arr.size(); i++){
            int cur = arr[i];
            mp[cur]--;
            for(int j = 1; j * j <= cur; j++){
                if((cur % j ==0) && (mp[j] || mp[cur / j])){
                   // cout<<arr[i]<<j<<endl;
                    ans++;
                    break;
                }
            }
            mp[cur]++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends