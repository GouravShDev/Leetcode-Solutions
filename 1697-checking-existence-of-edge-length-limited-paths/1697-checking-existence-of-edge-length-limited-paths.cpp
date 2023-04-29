class Solution {
public:
    vector<int> parent;
    int findParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
    void connect(int u , int v){
        u = findParent(u);
        v = findParent(v);
        parent[u] = v;
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<bool> ans(queries.size());
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        vector<pair<vector<int>, int>> querisWithIndex;
        sort(edgeList.begin(), edgeList.end(),[](auto &a, auto &b){
            return a[2] < b[2];
        } );
        for(int i = 0 ;i < queries.size(); i++){
            querisWithIndex.push_back({queries[i], i});
        }
        sort(querisWithIndex.begin(), querisWithIndex.end(), [](auto &a, auto &b){
           return a.first[2] < b.first[2]; 
        });
        int i = 0;
        for(auto &q : querisWithIndex){
            while(i < edgeList.size() && edgeList[i][2] < q.first[2]){
                connect(edgeList[i][0], edgeList[i][1]);
                i++;
            }
            ans[q.second] = findParent(q.first[0]) == findParent(q.first[1]);
        }
        // for(auto & it : edgeList){
        //     for(auto &i : it){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return ans;
    }
};