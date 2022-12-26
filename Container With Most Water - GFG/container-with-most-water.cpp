//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long A[], int len)
{
    long long ans = 0;
    int left = 0;
    int right = len-1;
    while(left < right){
        long long length = right - left;
        ans = max(ans , min(A[right], A[left]) * length);
        if(A[left] < A[right]){
            left++;
        }else{
            right--;
        }
    }
    return ans;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends