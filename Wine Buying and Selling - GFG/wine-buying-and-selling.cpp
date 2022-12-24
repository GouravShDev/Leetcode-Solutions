//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& Arr, int N){
      long long ans = 0;
      int i = 0;
      int j = 0;
    //   for(int k = 0 ; k  < N ; k++){
    //       if(Arr[k] > 0){
    //           i = k;
    //       }
    //       if(Arr[k] < 0){
    //           j = k;
    //       }
    //       if(i != -1 && j != -1)break;
    //   }
      while(i < N && j < N){
          if(Arr[i] <= 0){
              i++;
              continue;
          }
          if(Arr[j] >= 0){
              j++;
              continue;
          }
        //   cout<<Arr[i]<<" "<<Arr[j]<<endl;
          long long diff = Arr[i] + Arr[j];
          ans += min(abs(Arr[i]),  abs(Arr[j])) * abs(j - i);
          if(diff > 0){
              Arr[i] = diff;
              j++;
          }else if(diff < 0){
              Arr[j] = diff;
              i++;
          }else{
              i++;
              j++;
          }
      }
      return ans;
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
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends