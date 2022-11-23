class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32; i++){
            int x = 0;
            for(auto &num : nums){
                if(num & (1 << i)){
                    x++;
                }
            }
            if(x % 3){
                ans |= (1 << i);
            }
        }
        return ans;
    }
};