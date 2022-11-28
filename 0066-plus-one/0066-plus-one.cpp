class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int i = digits.size()-1;
        vector<int> ans;
        while(i >= 0){
            // cout<<digits[i] <<" ";
            if(digits[i] == 9 && carry){
                ans.push_back(0);
                carry = 1;
            }else{
                ans.push_back(digits[i]+carry);
                carry = 0;
            }
            i--;
        }
        if(carry) ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};