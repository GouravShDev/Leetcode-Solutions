class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> freqMp((1e4 * 2)+ 2);
        vector< vector<int>> valuesMp(nums.size() + 2);
        for(auto &num : nums) freqMp[num + 1e4]++;
        for(int i =0 ;i < 1e4 * 2 + 2 ; i++){
            if(freqMp[i])valuesMp[freqMp[i]].push_back(i - 1e4);
        }
        vector<int> ans;
            for(auto it = valuesMp.rbegin(); it != valuesMp.rend(); it++){
               for(auto &x : it[1]){
                ans.push_back(x);
                if(ans.size() == k) return ans;
            } 
            }
            
        
        return ans;
    }
};