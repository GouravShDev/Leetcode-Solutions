class Solution {
public:
    vector<int> parent;
    // int component;
    int findParent(int n ){
        if(n == parent[n]){
            return n;
        }
        return parent[n] = findParent(parent[n]);
    }
    void connect(int u , int v){
        int pu = findParent(u);
        int pv = findParent(v);
        parent[pv] = pu;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        parent.resize(n);
        iota(parent.begin(),parent.begin() + n, 0);
        
        int component = n;
        for(int i = 0 ; i < isConnected.size() ; i++){
            for(int j = 0; j < isConnected.size(); j++){
                if(isConnected[i][j] && findParent(i) != findParent(j)){
                    connect(i, j);
                    component--;
                }
            }
        }
        return component;
        
    }
};