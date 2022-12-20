//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 



// } Driver Code Ends
class Solution{
  public:
    int maxDistance(int a[], int n) 
    { 
        // |a[i] - a[j]| + |i-j|
        
        // ++ => a[i] + i - (a[j] + j)
        // +- => a[i] - i - (a[j] + j)
        // -+ => -(a[i] - i) - (a[j] + j)
        // -- => -(a[i] - i) + (a[j] + j)
        
        int max1=  INT_MIN;
        int min1 = INT_MAX;
        int max2 = INT_MIN;
        int min2 = INT_MAX;
        int ans = 0;
        for(int i =0; i < n ; i++){
            max1 = max(max1, a[i] + i);
            min1 = min(min1, a[i] + i);
            max2 = max(max2, a[i] - i);
            min2 = min(min2, a[i] - i);
        }
        ans= max(max1 - min1, max2 - min2);
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	    Solution obj;
	    cout<<obj.maxDistance(arr, n)<<endl;
	}
} 

// } Driver Code Ends