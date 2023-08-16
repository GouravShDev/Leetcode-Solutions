class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            while(!q.empty() && (nums[q.front()] < nums[i] || q.front() <= (i - k))){
                q.pop_front();
            }
            // if(!q.empty())
            // cout<<nums[q.front()]<<" "<<i<<endl;
            while(!q.empty() && (nums[q.back()] < nums[i])){
                q.pop_back();
            }
            q.push_back(i);
            if(i >= k - 1){
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};