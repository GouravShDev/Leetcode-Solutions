class Solution {
public:
    vector<int> parent;
    int findParent(int n ){
        if( n == parent[n]){
            return n;
        }
        return parent[n] = findParent(parent[n]);
    }
    void connect(int u, int v){
        int pv = findParent(v);
        int pu = findParent(u);
        parent[pv] = pu;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int components = n;
        int extra = 0;
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        for(int i =0 ;i < connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            if(findParent(u)  != findParent(v)){
                connect(u, v);
                components--;
            }else{
                extra++;
            }
        }
        if(extra < (components-1)){
            return -1;
        }else{
            return components-1;
        }
    }
};