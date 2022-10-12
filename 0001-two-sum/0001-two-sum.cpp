class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> answer;
        for(int i = 0; i < nums.size() ; i ++){
            if(m.find(target- nums[i]) != m.end()){
                answer.push_back(m[target- nums[i]]);
                answer.push_back(i);
                    break;
            }
            m.insert({ nums[i], i});
        }
        return answer;
    }
};