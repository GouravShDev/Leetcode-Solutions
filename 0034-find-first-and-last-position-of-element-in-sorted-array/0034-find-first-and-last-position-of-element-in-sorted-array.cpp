class Solution {
public:
    int bs(vector<int> &nums, int target, bool lastOcc){
        int start = 0;
        int end = nums.size()-1;
        int ans = -1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target){
                ans = mid;
                if(lastOcc) start = mid +1;
                else end = mid -1;
            }else
            if(nums[mid] < target){
                start = mid+1;
            }else{
                end = mid -1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {bs(nums, target, false), bs(nums,target, true)};
    }
};