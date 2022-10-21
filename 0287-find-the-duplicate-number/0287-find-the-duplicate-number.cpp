class Solution {
public:
    int getCount(vector<int> &nums, int num){
        int count = 0;
        for(auto &n: nums){
            if(n <= num){
                count++;
            }
        }
        return count;
    }
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        int start = 1;
        int end = n;
        int ans = 0;
        while(start <= end){
            int mid = (start + end)/2;
            if(getCount(nums, mid) <= mid){
                ans = mid;
                start = mid+1;
            }else{
                end = mid -1;
            }
        }
        return start;
    }
};