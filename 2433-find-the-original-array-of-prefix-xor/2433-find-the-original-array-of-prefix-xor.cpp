class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int x = 0;
        vector<int> ans;
        for(int i =0 ; i < pref.size(); i++){
            
            x ^= pref[i];
            
            ans.push_back(x);
            x= pref[i];
        }
        return ans;
    }
};