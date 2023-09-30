class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int,int>> stk; // { j , i }
        int curMin = nums[0];
        for(int k = 1 ; k < nums.size() ; k++){
            while(!stk.empty() && stk.top().first < nums[k]) stk.pop();
            
            if(!stk.empty() && stk.top().first > nums[k] && stk.top().second < nums[k]) return true;
            stk.push({nums[k] , curMin});
            curMin = min(curMin, nums[k]);
        }
        return false;
    }
};