class Solution {
public:
    map<string, int> parentMp;
    vector<int> indexParent;
    
    int findParent(int s){
        if( s == indexParent[s]){
            return s;
        }
        return indexParent[s] = findParent(indexParent[s]);
    }
    void merge(int u , int v){
        u = findParent(u);
        v = findParent(v);
        
        indexParent[v] = u;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // parent.resize(accounts.size());
        indexParent.resize(accounts.size());
        iota(indexParent.begin() , indexParent.end(),0);
        for(int i = 0 ; i < accounts.size() ; i++){
            for(int j = 1 ; j < accounts[i].size() ; j++){
                if(parentMp.find(accounts[i][j]) != parentMp.end()){
                    merge(i , parentMp[accounts[i][j]]);
                }else{
                    parentMp[accounts[i][j]] = i;
                }
            }
        }
        vector<vector<string>> ans;
        map<int, vector<string>> mp;
        for(auto &acc : parentMp){
            mp[findParent(acc.second)].push_back(acc.first);
        }
        for(auto &it: mp){
            vector<string> temp;
            temp.push_back(accounts[it.first][0]);
            sort(it.second.begin() ,it.second.end());
            temp.insert(temp.end() , it.second.begin(), it.second.end());
            ans.push_back(temp);
        }
        return ans;
    }
};