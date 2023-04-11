//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int solve(int a, int b, int c) {
       priority_queue<int> pq;
       if(a != 0)pq.push(a);
       if(b != 0)pq.push(b);
       if(c != 0)pq.push(c);
       
       while(!pq.empty()){
           int mxFreq = pq.top();
           pq.pop();
          if(mxFreq < 3) return a + b + c;
           mxFreq -= 2;
           
           
           
           if(pq.empty()) return -1;
           int secondFreq= pq.top();
           pq.pop();
           secondFreq--;
           if(mxFreq != 0) pq.push(mxFreq);
           if(secondFreq != 0) pq.push(secondFreq);
           
           
       }
       return a + b + c;
    }
};

// aababccb

// a = 3, b = 0,  c =1;


// aabaacaabaacaaaa

// a = 0 , b = 1 , c = 3

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        Solution ob;
        int ans = ob.solve(a, b, c);
     

        cout <<  ans << "\n";
    }
    return 0;
}
// } Driver Code Ends