class Solution {
public:
    bool isVecEq(vector<int> &a, vector<int> &b){
        for(int i =0 ; i < a.size(); i++){
            if(a[i] > b[i]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        vector<int> tarFreq(256);
        vector<int> curFreq(256);
        for(auto &ch : t){
            tarFreq[ch]++;
        }
        int i =0;
        int ansStart = 0;
        int ansEnd = s.size()-1;
        int flag = 0;
        for(int j = 0 ; j < s.size() ; j++){
            if(tarFreq[s[j]]) curFreq[s[j]]++;
            while(isVecEq(tarFreq, curFreq) && i < s.size()){
                flag = 1;
                if(ansEnd - ansStart > j - i){
                    ansStart = i;
                    ansEnd = j;
                }
                if(tarFreq[s[i]])curFreq[s[i]]--;
                i++;
            }
        }
        if(!flag) return "";
        return s.substr(ansStart, ansEnd-ansStart+1);
    }
};