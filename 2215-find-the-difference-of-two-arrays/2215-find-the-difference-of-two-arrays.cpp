class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> st1;
        set<int> st2;
        for(auto &it: nums1) st1.insert(it);
        for(auto &it: nums2) st2.insert(it);
        vector<vector<int>> ans(2, vector<int>());
        for(auto &it : st1){
            if(!st2.count(it)) ans[0].push_back(it);
        }
        for(auto &it : st2){
            if(!st1.count(it)) ans[1].push_back(it);
        }
        return ans;
    }
};