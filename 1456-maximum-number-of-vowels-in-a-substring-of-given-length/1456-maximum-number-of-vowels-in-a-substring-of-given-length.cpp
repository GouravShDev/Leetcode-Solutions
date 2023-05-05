class Solution {
public:
    bool isVowels(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int start =0 ;
        int ans = 0;
        int count = 0;
        for(int i =0 ; i < s.size() ; i++){
            if(i  >= k){
                if(isVowels(s[start])){
                    count--;
                }
                start++;
            }
            if(isVowels(s[i])) count++;
            ans = max(ans, count);
        }
        return ans;
    }
};