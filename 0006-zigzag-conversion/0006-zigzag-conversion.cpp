class Solution {
public:
    string convert(string s, int numRows) {
        int i =0;
        vector<string> ansVec(numRows, "");
        while( i  < s.size()){
            int j = 0;
            while(j < numRows && i < s.size()){
                ansVec[j++]+= s[i++];
            }
            // ansVec[j--]+= s[i++];
            j-= 2;
            while(j > 0 && i < s.size()){
                ansVec[j--]+= s[i++];
            }
        }
        string ans = "";
        for(int i= 0; i < numRows; i++){
            ans += ansVec[i];
        }
        return ans;
    }
};