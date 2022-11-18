class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32; i++){
            
            int count = 0;
            for( int num  : nums){
                if((num & (1 << i))){
                    count++;
                }
            }
            count %= 3;
            if(count > 0){
                ans |= 1 << i;
            }
        }
        //  for(int i = 0; i < 32; i++){
        //     if(ans & (1 << i) > 0)
        //         cout<<"1";
        //     else{
        //         cout<<"0";
        //     }
        // }
        return ans;
    }
};