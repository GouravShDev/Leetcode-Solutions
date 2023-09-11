class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
      vector<vector<int>> ans;
        vector<pair<int,int>> vp;
        for(int i =0 ; i < groupSizes.size(); i++){
            vp.push_back({groupSizes[i] , i});
        }
        sort(vp.begin(), vp.end());
        int i =0;
        while(i < groupSizes.size()){
            int reqSize = vp[i].first;
            vector<int> cur;
            while(cur.size() != reqSize){
                //cout<<cur.size()<<" " << reqSize<<endl;
                cur.push_back(vp[i++].second);
            }
            ans.push_back(cur);
            //i++;
        }
        return ans;
    }
};