class Solution {
public:
    string longestPalindrome(string s) {
        int ansStart = 0;
        int ansEnd = 0;
        for(int index = 0 ;index < s.size() ;index++){
            int i = index;
            int j = index;
            while(i >= 0 && j < s.size() && s[i] == s[j]){
                if(j - i > ansEnd - ansStart){
                    ansStart = i;
                    ansEnd = j;
                }
                i--;
                j++;
            }
            i = index-1;
            j = index;
            while(i >= 0 && j < s.size() && s[i] == s[j]){  
                if(j - i > ansEnd - ansStart){
                    ansStart = i;
                    ansEnd = j;
                }
                i--;
                j++;
            }
            
        }
        // cout<<ansStart<<" "<<ansEnd<<endl;
        return s.substr(ansStart , ansEnd-ansStart+1);
       
    }
};