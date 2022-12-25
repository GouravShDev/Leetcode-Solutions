class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> pref(n+1);
        for(int i=1 ; i <= n ; i++){
            pref[i] = nums[i-1] + pref[i-1];
            // cout<<pref[i]<<" ";
        }
        vector<int> ans;
        for(auto &q : queries){
            int ind = upper_bound(pref.begin(), pref.end(), q)-pref.begin()-1;
            ans.push_back(ind);
        }
        return ans;
    }
};