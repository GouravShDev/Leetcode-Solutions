class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) return false;
       int notSame = 0;
        vector<int> mp1(26);
        vector<int> mp2(26);
        bool isGreaterThan2 = false;
        for(int i = 0; i< s.size();i++){
            if(s[i] != goal[i]) notSame++;
            mp1[s[i]-'a']++;
            mp2[goal[i]-'a']++;
        }
        for(int i = 0 ; i < 26 ; i++){
            if(mp1[i] != mp2[i]) return false;
            if(mp1[i] > 1) isGreaterThan2 = true;
        }
        if(s == goal) return isGreaterThan2;
        if(notSame != 2) return false;
        return true;
    }
};