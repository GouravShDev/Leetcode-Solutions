class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n  = nums.size();
        vector<map<int,int>> vecMp(n);
        int ans = 0;
        for(int i = 1 ;i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                long long int dif =  (long long ) nums[i] - nums[j];
                if(dif >= INT_MAX || dif<= INT_MIN) continue;
                int diff = (int) dif;
                int prevJ = vecMp[j][diff];
                int prevI = vecMp[i][diff];
                ans += prevJ;
                vecMp[i][diff] = prevJ + prevI +  1;
            }
        }
        return ans;
    }
};