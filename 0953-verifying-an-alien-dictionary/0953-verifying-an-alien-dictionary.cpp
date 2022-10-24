class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> mp(26);
        for(int i =0 ; i < 26; i++){
            mp[order[i]-'a'] = i;
        }
        for(auto &word : words){
            for(auto &ch : word){
                ch = mp[ch-'a'];
            }
        }
        return is_sorted(words.begin(), words.end());
    }
};