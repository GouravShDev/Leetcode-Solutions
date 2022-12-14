//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isPossible(int arr[], int N, int k , int mid){
        int sum = 0;
        for(int i =0 ; i< N ;i++){
            sum += arr[i];
            if(sum > mid){
                if(arr[i] > mid) return false;
                sum = arr[i];
                k--;
            }
            if(k <= 0 )return false;
        }
        return true;
    }
    int splitArray(int arr[] ,int N, int K) {
        int start = 0;
        int end = accumulate(arr, arr+N, 0);
        int ans = -1;
        while(start <= end){
            int mid = start  + (end  - start )/2;
            if(isPossible(arr, N , K, mid)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
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
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends