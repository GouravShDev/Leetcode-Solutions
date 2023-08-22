class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans  = "";
        int num = columnNumber;
      while(num > 0){
          num--;
            ans += 'A' + ((num% 26));
            num/= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};