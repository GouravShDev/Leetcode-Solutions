class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
       vector<pair<int,int> > dp;
        dp.push_back({INT_MIN, 0});
        sort(pairs.begin() , pairs.end(),[] (auto &a , auto &b){
            return a[1] < b[1];
        });
        for(auto &p : pairs){
            cout<<""<<p[0]<<","<<p[1]<<"} ";
        }
        for(int i =0 ;i < pairs.size() ; i++){
            auto index = prev(lower_bound(dp.begin(), dp.end(), make_pair(pairs[i][0], 0) ) ) - dp.begin();
            if(dp[index].second + 1 > dp.back().second){
                dp.push_back({pairs[i][1], dp[index].second+1});
            }
        }
        return dp.back().second;
    }
};