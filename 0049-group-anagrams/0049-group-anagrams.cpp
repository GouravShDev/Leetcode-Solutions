class Solution {
public:
    string sortString(string s){
        vector<int> mp(26);
        for(auto &ch : s){
            mp[ch-'a']++;
        }
        string sortedString = "";
        for(int i= 0; i < 26; i++){
            int freq = mp[i];
            while(freq--){
             
            sortedString += i+'a'   ;
            }
        }
        return sortedString;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for(auto &str : strs){
            string s = str;
            sort(s.begin(), s.end());
            mp[s].push_back(str);
        }
        for(auto &it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};