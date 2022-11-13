class Solution {
public:
    string reverseWords(string s) {
        
        reverse(s.begin() , s.end());
        int lastStartIndex = -1;
        for(int i =0 ; i <= s.size(); i++){
            if((i == s.size() || s[i] == ' ') && lastStartIndex != -1){
                reverse(s.begin() + lastStartIndex, s.begin() + i);
                lastStartIndex = -1;
            }else{
                if(lastStartIndex == -1) lastStartIndex = i;  
            }
        }
        int j = 0;
        int index = -1;
        while(j < s.size() && s[j] == ' '){
            j++;
        }
        while(j < s.size()){
            if(index != -1 && s[index] == ' ' && s[j] == ' '){
                j++;
                continue;
            }
            s[++index] = s[j++];
        }
        if(s[index] == ' ') index--;
        return s.substr(0, index+1);
    }
};