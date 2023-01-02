//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int H[], int N) {
        vector<int> seq;
        for(int i =0 ;i <  N ; i++){
            if(!seq.empty() && seq.back() >= H[i]){
                int index = lower_bound(seq.begin() , seq.end(), H[i])- seq.begin();
                seq[index] = H[i];
            }
             else seq.push_back(H[i]);
        }
        return N - seq.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends