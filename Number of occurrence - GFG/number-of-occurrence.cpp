//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    auto left = upperBound(arr, arr+n, x);
	    auto right = upperBound(arr, arr+n, x-1);
	    return left - right;
	}
	int* upperBound(int* start, int* end, int val){
	    int *ans = end;
	    auto i = start;
	    auto j = end;
	    while(j - i >= 0){
	        int endIndex = j - start ;
	        int startIndex = i - start;
	        int mid = startIndex + (endIndex - startIndex)/2;
	        auto midItr = start + mid;
	        if(*midItr > val){
	            ans = midItr;
	            j = midItr-1;
	        }else{
	            i = midItr+1;
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
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends