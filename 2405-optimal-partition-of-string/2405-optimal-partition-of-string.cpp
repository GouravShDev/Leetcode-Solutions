class Solution {
public:
    int partitionString(string s) {
        vector<int> mp(26);
        int ans = 1;
        int l = 0;
        for(int r =0  ;r < s.size(); r++){
            if(mp[s[r]-'a']){
                ans++;
                mp = vector<int>(26);
            }
            mp[s[r]-'a']++;
            
        }
        return ans;
    }
};