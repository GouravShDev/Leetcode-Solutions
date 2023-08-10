class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target) return true;
            
            if(nums[start] == nums[mid]  && nums[mid] == nums[end]){
                int prevValue = nums[mid];
                while(start <= end && nums[start] == prevValue){
                    start++;
                }
                while(start <= end && nums[end] == prevValue){
                    end--;
                }
                 if(start > end) return false;
                mid = start + (end - start)/2;
            if(nums[mid] == target) return true;
                
            }
           
            
            // sorted check for left half
            if(nums[start] <= nums[mid]){
                // left Sorted
                if(nums[start] <= target && target <= nums[mid]){
                    end = mid-1;
                }else{
                    start = mid +1;
                }
            }else{
                // right Sorted
                if(nums[mid] <= target && target <= nums[end]){
                    start = mid +1;
                    
                }else{
                    end = mid -1;
                }
            }
        }
        return false;
    }
};