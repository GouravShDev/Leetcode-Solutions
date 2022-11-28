class Solution {
public:
    char findTheDifference(string s, string t) {
        int ansAsc = 0;
        for(int i = 0; i < s.size() ; i++){
            ansAsc ^= s[i];
            ansAsc ^= t[i];
        }
        ansAsc ^= t[t.size()-1];
        char ans = ansAsc;
        return ans;
    }
};