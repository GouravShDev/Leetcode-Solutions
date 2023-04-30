class Solution {
public:
    bool isSame(vector<int> &parent, int u, int v){
        return findParent(parent, u) == findParent(parent , v);
    }
    int findParent(vector<int> &parent, int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent, parent[node]);
    }
    void connect(vector<int> &parent, int u, int v , int &comp){
        u = findParent(parent,u);
        v = findParent(parent, v);
        if(u == v) return;
        comp--;
        parent[u] = v;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> aliceParent(n);
        vector<int> bobParent(n);
        iota(aliceParent.begin(), aliceParent.end(), 0);
        iota(bobParent.begin(), bobParent.end(), 0);
        sort(edges.begin(), edges.end(), [](auto &a , auto &b){
           return a[0] > b[0]; 
        });
        int aliceComp = n;
        int bobComp = n;
        int ans = 0;
        for(auto &edge : edges){
            int type = edge[0];
            int u = edge[1]-1;
            int v = edge[2]-1;
            if(type == 3){
                if(isSame(aliceParent, u, v) && isSame(bobParent, u , v)){
                    ans++;
                    continue;
                }
                connect(aliceParent, u , v, aliceComp);
                connect(bobParent, u , v, bobComp);
            }
            if(type == 2){
                if(isSame(bobParent, u , v)){
                    ans++;
                    continue;
                }
                connect(bobParent, u, v, bobComp);
            }
            if(type == 1){
                if(isSame(aliceParent, u ,v)){
                    ans++;
                    continue;
                }
                connect(aliceParent, u , v, aliceComp);
            }
        }
        if(bobComp > 1 || aliceComp > 1) return -1;
        return ans;
    }
};