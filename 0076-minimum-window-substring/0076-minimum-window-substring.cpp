class Solution {
public:
    string minWindow(string s, string t) {
        int counter = t.size();
        vector<int> curMp(256);
        int i =0;
        for(auto &ch : t){
            curMp[ch]++;
        }
        int start = 0;
        int end = INT_MAX;
        
        // A = 1 , B = 1 , C= 1
        // a , freq = 0;
        for(int j =0 ; j < s.size(); j++){
            if(curMp[s[j]]-- > 0) counter--;
            while(counter == 0){
                if(end - start > j - i){
                    start = i;
                    end = j;
                }
                if(curMp[s[i]]++ == 0 )counter++;
                i++;
            }
            
        }
        
        
        return end != INT_MAX ? s.substr(start , end - start  +1) : "";
    }
};