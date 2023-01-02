class Solution {
public:
    bool isCapital(char c){
        return c >= 'A' and c <= 'Z';
    }
    bool detectCapitalUse(string word) {
        int count = 0;
        for(auto &ch : word){
            if(isCapital(ch)) count++;
        }
        if(count == word.size() || count == 0) return true;
        if(count == 1 && isCapital(word[0])) return true;
        return false;
    }
};