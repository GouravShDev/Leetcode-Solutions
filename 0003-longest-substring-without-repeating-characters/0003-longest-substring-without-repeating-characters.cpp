class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lastRepeated = -1;
        int ans = 0;
        vector<int> mp(256,-1);
        for(int i =0 ; i < s.size() ; i++){
            if(mp[s[i]] != -1){
                lastRepeated = max( lastRepeated, mp[s[i] ]);
            }
            ans = max(ans, i - lastRepeated);
            mp[s[i]] = i;
        }
        
        return ans;
    }
};