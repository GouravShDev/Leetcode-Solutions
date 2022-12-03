class Solution {
public:
    int parition(vector<int> &nums, int start , int end){
        if(start == end) return start;
        int pivot = nums[start];
        int p = start;
        int i = start;
        int j = end;
        // [ P xx x x  xx xxxxx  ]
        while(start < end){
             //cout<< start <<" " << end<<endl;
            while(start < j && nums[start] <= pivot){
                start++;
            }
            while(i < end && nums[end] > pivot){
                end--;
            }
            if(start < end) swap(nums[start++], nums[end--]);
        }
        swap(nums[end] , nums[p]);
        return end;
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