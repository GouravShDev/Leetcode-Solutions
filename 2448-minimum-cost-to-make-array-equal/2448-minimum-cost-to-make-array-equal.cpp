class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<int,int>> costNum;
        for(int i =0 ;i < nums.size();i++){
            costNum.push_back({nums[i],cost[i]});
        }
        sort(costNum.begin(), costNum.end());
        vector<long long> pref(nums.size(), costNum[0].second);
        vector<long long> suff(nums.size(), costNum[nums.size()-1].second);
        for(int i = 1 ; i< nums.size(); i++){
            int j = nums.size()-1 - i;
            pref[i] = costNum[i].second + pref[i-1];
            suff[j] = costNum[j].second + suff[j+1];
        }
        //  for(int i = 0 ;i< nums.size(); i++){
        //     cout<<costNum[i].first<<":"<< costNum[i].second<<" ";
        // }
        // cout<<endl;
        // for(int i = 0 ;i< nums.size(); i++){
        //     cout<<pref[i]<<" ";
        // }
        // cout<<endl;
        //  for(int i = 0 ;i< nums.size(); i++){
        //     cout<<suff[i]<<" ";
        // }
        // cout<<endl;
        vector<long long> left(nums.size());
        vector<long long> right(nums.size());
        for(int i =1 ; i < nums.size();i++){
            left[i] = left[i-1] + ( (long long)costNum[i].first - costNum[i-1].first) * pref[i-1];
        }
        
        long long ans = left[nums.size()-1];
        for(int j = nums.size()-2; j >= 0; j--){
            right[j] = right[j+1] + ( (long long)costNum[j+1].first - costNum[j].first ) * suff[j+1];
            ans = min(ans, right[j] + left[j]);
        }
      
        return ans;
    }
};

// 1  2 3 5
// 2 14 3 1