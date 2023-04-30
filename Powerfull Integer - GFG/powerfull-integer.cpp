//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
        vector<pair<int,bool>> arr;
        for(auto &it: intervals){
            arr.push_back({it[0], false});
            arr.push_back({it[1], true});
        }
        sort(arr.begin(), arr.end());
        int cur = 0;
        int ans = -1;
        for(auto &it : arr){
            
            if(cur >= k){
                ans = max(ans , it.first);
            }if(it.second) cur--;
            else cur++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends