class Solution {
public:
    bool checkIfPangram(string sentence) {
        if(sentence.size() < 26) return false;
        vector<int> mp(26, 0);
        for(auto &ch : sentence){
            mp[ch-'a']++;
        }
        for(auto &it: mp){
            if(it < 1) return false;
        }
        return true;
    }
};