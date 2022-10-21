class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 0;
        int wnd = 0;
        int start = 0;
        for(int i = 0; i < nums.size(); i++){
            while(start <= i && wnd & nums[i]){
                wnd ^= nums[start++];
            }
            wnd |= nums[i];
            ans = max(ans, i - start +1);
        }
        return ans;
    }
};