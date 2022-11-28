class Solution {
public:
    char findTheDifference(string s, string t) {
        int sSum = 0;
        for(int i =0 ; i < s.size() ; i++){
            sSum -= s[i] - 'a';
            sSum += t[i] - 'a';
        }
        sSum += t[t.size()-1] - 'a';
        char ans = sSum + 'a' ;
        return ans;
    }
};