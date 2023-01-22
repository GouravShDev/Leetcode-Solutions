//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
  vector<int> factors;
    void getFactors(int n){
         for(int i = 1; i  * i <= n; i++){
             if(n % i == 0){
                 factors.push_back(i);
                 factors.push_back(n/i);
             }
         }
    }
    int solve(int N, int K, vector<int> &arr) {
        int sum = accumulate(arr.begin() , arr.end(), 0);
        getFactors(sum);
        int count = 0;
        int curSum = 0;
        int ans = 1;
        for(auto &fac : factors){
            curSum = 0;
            count = 0;
            for(int i =0 ;i < arr.size() ;i ++){
                curSum += arr[i];
                if(curSum % fac == 0){
                    count++;
                    curSum = 0;
                }
            }
            if(count >= K){
                ans = max(ans, fac);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> arr(N);
        Array::input(arr,N);
        
        Solution obj;
        int res = obj.solve(N, K, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends