class Solution {
public:
    int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> prev(n,-1);
        vector<int> next(n,n);
        stack<int> stk;
        for(int i =0 ;i < n; i++){
            while(!stk.empty() && arr[stk.top()] >= arr[i]){
                next[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        for(int i =n-1;i >= 0; i--){
            while(!stk.empty() && arr[stk.top()] > arr[i]){
                prev[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        int ans = 0;
        for(int i =0;i < n ; i++){
            
            int len = ((next[i]-i) * (i - prev[i] * 1LL) % mod);
            // cout<<len<<" " ;
            ans +=  (arr[i] * 1LL * len)  % mod;
            ans %= mod;
        }
        return ans;
    }
};