class Solution {
public:
    bool isPossible(vector<int> &nums, int p, int mid){
        int count = 0;
        int i = 0;
        while( i < nums.size()-1){
            if(nums[i+1] - nums[i] <= mid ){
                count++;
                i++;
            } 
            i++;
        }
        return count >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int start = 0;
        int end = nums[n-1] - nums[0];
        int ans = -1;
        while(start <= end){
            int mid = start + (end - start) /2;
            if(isPossible(nums, p , mid)){
                ans = mid;
                end = mid -1;
            }else{
                start = mid +1;
            }
        }
        return ans;
    }
};

// [10,1,2,7,1,3]
// 1 1 2 3 7 10
// 1 2 2 3 3 4 => p = 2
// 1 => 
// 0 =>