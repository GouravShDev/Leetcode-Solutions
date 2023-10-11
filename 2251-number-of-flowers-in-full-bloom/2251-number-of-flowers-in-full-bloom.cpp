class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, vector<int>> mp;
              vector<int> start, end;
        for (auto& t : flowers)
            start.push_back(t[0]), end.push_back(t[1]);
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        vector<int> res;
        for (int t : people) {
            int started = upper_bound(start.begin(), start.end(), t) - start.begin();
            int ended = lower_bound(end.begin(), end.end(), t) - end.begin();
            res.push_back(started - ended);
        }
        return res;
    
        vector<int> ans(people.size());
        for(int i = 0 ;i < people.size(); i++){
            mp[people[i]].push_back(i);
        }
        sort(people.begin() , people.end());
        
        vector<pair<int,bool>> vp;
        for(auto flower : flowers){
            vp.push_back({flower[0], false});
            vp.push_back({flower[1], true});
        }
        sort(vp.begin(), vp.end());
        long long cur = 0;
        int i = 0;
        int j = 0;
        while(i < vp.size() && vp[i].first > people[j]){
            j++;
        }
        while( i < vp.size() && j < people.size()){
            
            if(!vp[i].second){
                cur ++;
            }
            if( i+1 == vp.size() || people[j] < vp[i+1].first){
                
                for(auto index : mp[people[j]]){
                    ans[index] = cur;
                }
                do{
                    j++;   
                }while(j<people.size() &&people[j-1]== people[j]);
            }
             if(vp[i].second){
                cur --;
            }
            i++;
        }
        return ans;
        
        
    }
};