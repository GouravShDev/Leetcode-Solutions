class Solution {
public:
    bool isVowel(char c){
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int getCount(string s, int i , int j ){
        int count = 0;
        while(i <= j){
            if(isVowel(s[i])){
                count++;
            }
            i++;
        }
        return count;
    }
    bool halvesAreAlike(string s) {
        return getCount(s, 0, s.size()/2-1) == getCount(s, s.size()/2, s.size()-1);
    }
};