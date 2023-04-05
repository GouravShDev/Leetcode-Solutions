class Solution {
public:
    bool isPossible(vector<int> &nums, int maxVal){
        long long last = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]-last > maxVal) return false;
            last = maxVal - (nums[i] - last);
        }
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int start = 0;
        int end = 1e9;
        int ans = -1;
        while(start <=end){
            int mid = start + (end - start)/2;
            if(isPossible(nums, mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
    }
};