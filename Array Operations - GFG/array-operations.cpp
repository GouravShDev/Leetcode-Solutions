//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        int count = 0;
        bool lastZero = true;
        bool isZeroPresent = false;
        for(int i=0;i<n;i++)
        {
            if(!lastZero && arr[i] == 0) count++;
            if(arr[i] == 0){
                lastZero = true;
            }else{
                lastZero = false;
            }
            if(arr[i] == 0) isZeroPresent = true;
        }
        if(!isZeroPresent) return -1;
        if(!lastZero) count++;
        return count;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends