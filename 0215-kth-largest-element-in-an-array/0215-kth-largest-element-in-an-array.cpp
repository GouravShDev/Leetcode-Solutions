class Solution {
public:
     int parition(vector<int> &nums, int i, int j){
        int pivotIndex = i++;
        int end = j;
        while(i <= j){
            while( i <= end && nums[i] < nums[pivotIndex]){
                i++;
            }
            while( j >= pivotIndex && nums[j] > nums[pivotIndex]){
                j--;
            }
           if(i <= j){
                swap(nums[i++], nums[j--]);
            }
        }
        swap(nums[pivotIndex] , nums[j]);
        return j;
    }
    int quickSelect(vector<int> &nums, int start ,int end, int k){
        if(start == end ) return nums[start];

        int pivotIndex = parition(nums, start, end);
        //cout<<pivotIndex;
        if(pivotIndex == (nums.size() - k)) return nums[pivotIndex];
        if(pivotIndex > (nums.size() - k)){
            return quickSelect(nums, start ,pivotIndex-1, k);
        }
           return quickSelect(nums, pivotIndex+1, end, k);
        
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0 , nums.size()-1, k);
    }
};