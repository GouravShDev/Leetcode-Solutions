//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        sort(arr.begin() , arr.end());
        long long ans = 0;
        for(int i = 1  ;i < arr.size() ; i++){
            if(arr[i-1] == arr[i]){
                arr[i]++;
                ans++;
            }else if(arr[i-1] > arr[i]){
                ans +=  arr[i-1] - arr[i] +1;
                arr[i] = arr[i-1]+1;
            }
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
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends