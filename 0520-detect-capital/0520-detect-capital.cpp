class Solution {
public:
    bool isCapital(char c){
        return c >= 'A' and c <= 'Z';
    }
    bool detectCapitalUse(string word) {
        bool firstWordCap = isCapital(word[0]);
        int flag = 0;
        for(int i =1  ; i < word.size(); i++){
            bool curCap = isCapital(word[i]);
            if(!firstWordCap && curCap){
                return false;
            }if(firstWordCap && curCap && flag == 0){
                flag = 1;
            }else if(firstWordCap && !curCap && flag == 0){
                flag = -1;
            }else if(flag == -1 && curCap){
                return false;
            }else if(flag == 1 && !curCap){
                return false;
            }
        }
        return true;
    }
};