class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size()) return {};
        vector<int> ans;
        vector<int> count(26);
        vector<int> cur(26);
        for(int i =0 ; i < p.size(); i++){
            count[p[i]-'a']++;
            cur[s[i]-'a']++;
        }
        if(count == cur) ans.push_back(0);
        // cur[s[0]-'a']--;
        for(int i = 0;  i < s.size() - p.size(); i++){
            cur[s[i]-'a']--;
            cur[s[i+p.size()]-'a']++;
            if(cur == count) ans.push_back(i+1);
            
        }
        return ans;
    }
};