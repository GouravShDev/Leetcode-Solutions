class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for(int i = 0 ; i < 32 ; i++){
            int mask = 1 << i;
            int aCount = (a & mask) > 0;
            int bCount = (b & mask) > 0;
            int cCount = (c & mask) > 0;
            if(cCount){
                if(!(aCount || bCount)){
                    ans++;
                }
            }else{
                ans += (aCount + bCount);
            }
        }
        return ans;
    }
};