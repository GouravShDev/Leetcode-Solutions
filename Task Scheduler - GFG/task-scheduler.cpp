//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
              int sz = max(26, K + 1);
        vector<int>freq(sz, 0);
        for(auto &task : tasks)
        {
            freq[task - 'A']++;
        }

        sort(freq.rbegin(), freq.rend());
        int mx = freq[0];
        int idle = 0;
        for(int i = 0; i <= K; i++)
        {
            if(freq[i] == mx || freq[i] == mx - 1)continue;
            idle += (mx - 1 - freq[i]);
        }

        for(int i = K + 1; i < sz; i++)
        {
            idle -= freq[i];
        }
        return N + max(0, idle);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends