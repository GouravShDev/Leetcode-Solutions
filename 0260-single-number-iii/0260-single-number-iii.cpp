class Solution {
public:
    int getRightMostBit(int n){
        int pos = 0;
        while(n){
            if(n & 1){
                return pos;
            }
            n >>= 1;
            pos++;
        }
        return -1;
    }
    vector<int> singleNumber(vector<int>& nums) {
        int xorr = 0;
        for(auto &num : nums){
            xorr ^= num;
        }
        int pos = getRightMostBit(xorr);
        
        int x = 0;
        int y = 0;
        for(auto &num : nums){
            int mask = 1 << pos;
            if(num & mask){
                x ^= num;
            }else{
                y ^= num;
            }
        }
        return {x , y};
    }
};