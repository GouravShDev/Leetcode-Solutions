//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        int count = 0;
        int start = 0;
        int mxCount = 0;
        int end = 0;
        int ansStart = 0;
        int ansEnd = -1;
        for(int i =0 ; i < n; i++){
            if(a[i] == 0){
                count++;
                if(count > mxCount){
                    
                end = i;
                  ansStart = start;
                ansEnd = end;
                }
            }else{
                count--;
                if(count < 0){ count= 0; start= i+1;end = i;}
            }
            mxCount = max(mxCount, count);
            // if((end - start + 1) > (ansEnd -ansStart + 1)){
              
            // }
        }
        for(int i = ansStart ; i <= ansEnd; i++){
            a[i] = (a[i] == 0) ? 1 : 0;
        }
        
        return accumulate(a, a+n , 0);
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends