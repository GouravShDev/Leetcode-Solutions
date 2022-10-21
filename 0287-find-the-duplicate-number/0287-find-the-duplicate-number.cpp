class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while(slow == 0 || slow != fast ){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = 0;
        while(slow == 0 || slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};