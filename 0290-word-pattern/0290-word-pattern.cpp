class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;
        map<char,string> mp;
        map<string, char> mp2;
        int i = 0;
        while(ss >>word){
            if((mp.count(pattern[i]) && mp[pattern[i]] != word) || mp2.count(word) && mp2[word] != pattern[i]){
                return false;
            }
            mp[pattern[i]] = word;
            mp2[word] = pattern[i];
            i++;
        }
        return i == pattern.size();
    }
};