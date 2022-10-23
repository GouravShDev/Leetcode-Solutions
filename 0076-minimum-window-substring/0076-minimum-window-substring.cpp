class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> targetMp(256), curMp(256);
        for(auto &ch : t){
            targetMp[ch]++;
        }
        int start = 0;
        int end = INT_MAX;
        int counter = 0;
        int i = 0;
        for(int j = 0; j < s.size() ; j++){
            if(targetMp[s[j]]){
                if(curMp[s[j]] < targetMp[s[j]]) counter++;
                curMp[s[j]]++;
            }
            while(counter == t.size()){
                if(end - start > j - i){
                    start = i;
                    end = j;
                }
                if(targetMp[s[i]] > 0){
                    curMp[s[i]]--;
                    if(curMp[s[i]] < targetMp[s[i]]){
                        counter--;
                    }
                }
                i++;
            }
        }
        return end != INT_MAX? s.substr(start ,end-start + 1) :"";
    }
};