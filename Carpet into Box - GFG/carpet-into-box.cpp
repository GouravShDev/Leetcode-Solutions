//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int A, int B, int C, int D){
        int a = A;
        int b=  B;
        int c = C;
        int d = D;
        int x = 0;
        int y = 0;
        while(a > C){
            a /= 2;
            x++;
        }
        while(b>D){
            b /= 2;
            x++;
        }
        a = A;
        while(a > D){
            a /=2;
            y++;
        }
        b= B;
        while(b > C){
            b /=2;
            y++;
        }
        return min(x, y);
    }
    
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends