class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> mp(256);
        for(int i =0 ; i < order.size(); i++){
            mp[order[i]] = i;
        }
        for(int i =0 ; i< words.size()-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            int size = min(s1.size() , s2.size());
            int flag = 1;
            for(int j =0 ;j < size; j++){
                if(s1[j] == s2[j]) continue;
                flag = 0;
                if(mp[s1[j]] > mp[s2[j]]) return false;
                break;
            }
            if(flag && s1.size() > s2.size()){
                return false;
            }
        }
        return true;
    }
};