class Solution {
public:
    vector<int> getMap(string s){
        vector<int> mp(26);
        for(auto &ch : s){
            mp[ch-'a']++;
        }
        return mp;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        for(auto &s : strs){
            vector<int> m = getMap(s);
            mp[m].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto &it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};