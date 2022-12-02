class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size())return false;
        map<char,int> mp1;
        map<char,int> mp2;
        for(auto &ch : word1){
            mp1[ch]++;
        }
        for(auto &ch : word2){
            if(mp1.find(ch) == mp1.end() )return false;
            mp2[ch]++;
        }
        for(auto &ch : word1){
            if(mp2.find(ch) == mp2.end()) return false;
        }
        
        map<char, int> mp3;
        map<char, int> mp4;
        for(char c = 'a'; c <= 'z'; c++){
            if(mp1[c] > 0) mp3[mp1[c]]++;
            if(mp2[c] > 0) mp4[mp2[c]]++;
        }
        
        return mp3 == mp4;
        
        
    }
};