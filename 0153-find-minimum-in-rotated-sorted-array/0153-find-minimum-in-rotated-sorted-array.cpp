class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int start= 0;
        int n = nums.size();
        int end = nums.size()-1;
        while(start <= end){
            int mid = (start + end)/2;
            //cout<<mid<<endl;
            int leftAdj = mid-1 < 0 ? n-1 : mid-1;
            int rightAdj = mid+1 >= n ? 0 : mid+1;
            if(nums[leftAdj] > nums[mid] && nums[mid] < nums[rightAdj]){
                return nums[mid];
            }else if(nums[leftAdj] > nums[mid] || nums[mid] > nums[rightAdj] || nums[n-1] < nums[mid]){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return -1;
    }
};