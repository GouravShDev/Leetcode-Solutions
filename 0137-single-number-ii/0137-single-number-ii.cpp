class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unsigned int ans = 0;
        for(int i = 0; i < 32; i++){
            int count = 0;
            for(unsigned int num  : nums){
                if((num & (1 << i)) > 0){
                    count++;
                }
            }
            count %= 3;
            if(count > 0){
                ans |= 1 << i;
            }
        }
        return ans;
    }
};