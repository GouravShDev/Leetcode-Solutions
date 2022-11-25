class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        
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
        
        vector<int> prev2(n,-1);
        vector<int> next2(n,n);
        stack<int> stk2;
        
        for(int i =0 ;i < n; i++){
            while(!stk2.empty() && arr[stk2.top()] <= arr[i]){
                next2[stk2.top()] = i;
                stk2.pop();
            }
            stk2.push(i);
        }
        for(int i =n-1;i >= 0; i--){
            while(!stk2.empty() && arr[stk2.top()] < arr[i]){
                prev2[stk2.top()] = i;
                stk2.pop();
            }
            stk2.push(i);
        }
        
        long long ans = 0;
        for(int i =0;i < n ; i++){
            
            int len = ((next[i]-i) * (i - prev[i] * 1LL)) ;
            int len2 = ((next2[i]-i) * (i - prev2[i] * 1LL) );
            // cout<<len<<" " ;
            ans -=  (arr[i] * 1LL * len) ;
            ans +=  (arr[i] * 1LL * len2) ;
        }
        return ans;
    }
};