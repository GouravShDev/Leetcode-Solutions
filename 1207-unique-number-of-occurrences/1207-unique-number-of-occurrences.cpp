class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp;
        set<int> st;
        for(auto &ar : arr){
            mp[ar]++;
        }
        for(auto &it : mp){
            if(st.find(it.second) != st.end()) return false;
            st.insert(it.second);
        }
        return true;
    }
};