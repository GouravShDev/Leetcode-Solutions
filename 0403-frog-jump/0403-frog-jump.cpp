class Solution {
public:
    bool solve(map<int,int> &mp, int cur, int lastJump , int destination,   set<pair<int,int>> &dp){
        if(!mp.count(cur)) return false;
        if(cur > destination) return false;
        if(cur == destination) return true;
        if(dp.count({cur, lastJump})) return false;
        dp.insert({cur, lastJump});
        return solve(mp , cur + lastJump-1, lastJump-1, destination,dp) || solve(mp,cur+lastJump, lastJump, destination,dp) || solve(mp, cur + lastJump+1, lastJump+1, destination,dp);
    }
    bool canCross(vector<int>& stones) {
        map<int,int> mp;
        for(int i = 0 ;i < stones.size(); i++){
            mp[stones[i]] = i;
        }
        set<pair<int,int>> st;
        return solve(mp, 1, 1, stones[stones.size()-1], st);
    }
};