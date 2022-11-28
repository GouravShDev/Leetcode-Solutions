class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> wins;
        map<int,int> lose;
        for(auto match : matches){
            wins[match[0]]++;
            lose[match[1]]++;
        }
        vector<vector<int>> ans(2);
        for(auto &it : wins){
            if(!lose.count(it.first)){
                ans[0].push_back(it.first);
            }
        }
        sort(ans[0].begin(), ans[0].end());
        for(auto &it : lose){
            if(it.second == 1){
                ans[1].push_back(it.first);
            }
        }
        sort(ans[1].begin() ,ans[1].end());
        return ans;
    }
};