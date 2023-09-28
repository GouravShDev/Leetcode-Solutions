class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//         int i = nums.size();
//         int j = nums.size();
//         for(int k = nums.size()-1; k >= 0; k--){
            
//         }
        int i = 0;
        int j = nums.size()-1;
        while(i < j){
            while(i < j && nums[i] % 2 == 0) i++;
            while(i < j && nums[j] & 1) j--;
            swap(nums[i++], nums[j--]);
        }
        return nums;
    }
};