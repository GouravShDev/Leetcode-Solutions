class SummaryRanges {
public:
    vector<int> parents;
    //set<int> nums;
    map<int, pair<int,int>> mp;
    int find(int u){
        if( u == parents[u]) return u;
        return parents[u] = find(parents[u]);
    }
    void unionn(int u , int v){
        u = find(u);
        v = find(v);
        if(u == v) return;
        parents[u] = v;
    }
    SummaryRanges() {
        parents.resize(1e4+1);
        iota(parents.begin() , parents.end() , 0);
    }
    
    void addNum(int value) {
       // nums.insert(value);
        
        if(!mp.count(value)){
            mp[value] = {value, value};
        }
        if(mp.count(value-1)){
            int pV = find(value-1);
            auto oldV = mp[pV];
            auto oldP = mp[find(value)];
            unionn(value, value-1);
            pV = find(value);
            mp[pV] = {min(oldV.first, oldP.first) , max(oldV.second, oldP.second)};
         //   cout<<mp[pV].first<<" "<<mp[pV].second<<endl;
        }
        if(mp.count(value+1)){
            int pV = find(value+1);
            auto oldV = mp[pV];
            auto oldP = mp[find(value)];
            unionn(value, value+1);
            pV = find(value);
            mp[pV] = {min(oldV.first, oldP.first) , max(oldV.second, oldP.second)};
        }
    }
    
    vector<vector<int>> getIntervals() {
     vector<vector<int>> ans;
        int lastP = -1;
        set<int> unqParents;
        for(auto &it: mp){
            unqParents.insert(find(it.first));
        }
        for(auto &it : unqParents){
            auto cur = mp[it];
            ans.push_back({cur.first, cur.second});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */