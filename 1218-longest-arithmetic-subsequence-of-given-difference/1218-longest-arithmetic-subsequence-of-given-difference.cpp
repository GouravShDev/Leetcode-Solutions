class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int,int> mp;
        int n = arr.size();
        int ans =0 ;
        for(int i = 0 ;i < n ; i++){
            mp[arr[i]] = 1 + mp[arr[i] - difference];
            ans = max(ans, mp[arr[i]]);
        }
        return ans;
    }
};