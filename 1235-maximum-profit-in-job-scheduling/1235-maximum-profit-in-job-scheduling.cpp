class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<int,int> > dp;
        vector<pair<int, pair<int,int> >> vec;
        for(int i =0 ;i < startTime.size(); i++){
            vec.push_back({endTime[i], {startTime[i], profit[i]}});
        }
        dp.push_back({0, 0});
        sort(vec.begin() , vec.end());
        for(int i = 0; i < vec.size(); i++){
            auto end = vec[i].first;
            auto [st, pft] = vec[i].second;
            auto it = prev(upper_bound(dp.begin(), dp.end(), make_pair(st, INT_MAX)));
            // for(auto & it : dp){
            //     cout<<it.first<<" "<<it.second << endl;
            // }
            // cout<<st<<" => " << it->second<<endl;
            if(dp.back().second < pft + it->second){
                dp.push_back({end, pft + it->second});
            }
        }
        return dp.back().second;
    }
    
};