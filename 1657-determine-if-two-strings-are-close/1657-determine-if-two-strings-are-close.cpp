class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> mp1(26,0), mp2(26,0), mp3(26,0), mp4(26,0);
        for(auto &ch : word1){
            mp1[ch-'a']++;
            mp3[ch-'a'] = 1;
        }
        for(auto &ch : word2){
            mp2[ch-'a']++;
            mp4[ch-'a'] = 1;
        }
        sort(mp1.begin(), mp1.end());
        sort(mp2.begin(), mp2.end());
        return mp1 == mp2 && mp3 == mp4;
    }
};