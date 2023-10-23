class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 0) return false;
        int count = 0;
        for(int i = 0 ; i< 32 ; i++){
            int mask = 1 << i;
            bool isOne = mask & n;
            if(isOne){
                if(i & 1) return false;
                count++;
            }
            if(count > 1) return false;
        }
        return true;
    }
};