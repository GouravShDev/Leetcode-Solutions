class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1) return nums[0] == target ? 0 : -1;
        int n = nums.size();
        int start =0 ;
        int end = n-1;
        while(start <= end){
            int mid = (start + end )/ 2;
            if(nums[mid] == target ){
                return mid;
            }else if(nums[mid] > target){
                end = mid -1;
            }else{
                start = mid+1;
            }
        }
        return -1;
    }
};