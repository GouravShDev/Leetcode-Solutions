class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int> mp;
        int ans = -1;
        for(int &num : nums){
                mp.insert(num);
            
            if(mp.find(-num) != mp.end() && abs(ans) <= abs(num)){
                ans = abs(num);
            }
        }
    return ans;
    }
};