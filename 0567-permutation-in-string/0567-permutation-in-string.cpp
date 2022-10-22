class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> targetMp(256);
        vector<int> curMap(256);
        for(int i =0 ; i < s1.size() ;i++){
            targetMp[s1[i]]++;
        }
        int window = s1.size();
        
        for(int i = 0; i < window; i++){
            curMap[s2[i]]++;
        }
        if(curMap == targetMp) return true;
        for(int i = 0; i < s2.size()-window ; i++){
            curMap[s2[i]]--;
            curMap[s2[i+window]]++;
            if(curMap == targetMp) return true;
        }
        return (curMap== targetMp);
    }
};