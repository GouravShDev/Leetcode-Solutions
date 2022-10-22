class Solution {
public:
    vector<int> findAnagrams(string s2, string s1) {
       if(s1.size() > s2.size()) return {};
        vector<int> targetMp(256);
        vector<int> curMap(256);
        for(int i =0 ; i < s1.size() ;i++){
            targetMp[s1[i]]++;
        }
        int window = s1.size();
        
        for(int i = 0; i < window; i++){
            curMap[s2[i]]++;
        }
        vector<int> ans;
        if(curMap == targetMp) ans.push_back(0);
        for(int i = 0; i < s2.size()-window ; i++){
            curMap[s2[i]]--;
            curMap[s2[i+window]]++;
            if(curMap == targetMp) {
                ans.push_back(i+1);
            };
        }
        return ans; 
    }
};