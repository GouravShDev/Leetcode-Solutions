class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        vector<int> vec;
        vector<int> ans;
        for(auto &num : nums){
            if(vec.size() > 0 && vec.back()  > num){
                auto index =upper_bound(vec.begin(), vec.end(), num) - vec.begin();
                vec[index] = num;
                ans.push_back(index+1);
            }else{
                vec.push_back(num);
                ans.push_back(vec.size());
            }
        }
        return ans;
    }
};