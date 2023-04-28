class Solution {
public:
    vector<int> parent;
    int comp;
    int findParent(int u){
        if(parent[u] == u) return u;
        return parent[u] = findParent(parent[u]);
    }
    
    void connect(int u, int v){
        u = findParent(u);
        v = findParent(v);
        if(u == v) return;
        comp--;
        parent[v] = u;
    }
    bool isSimilar(string &s1, string &s2){
        int similarChar = 0;
        for(int i =0 ; i < s1.size(); i++){
            if(s1[i] == s2[i]) similarChar++;
        }
        return similarChar >= s1.size()-2;
    }
    int numSimilarGroups(vector<string>& strs) {
        parent.resize(strs.size());
        comp = strs.size();
        iota(parent.begin(), parent.end(), 0);
        for(int i =0 ; i< strs.size(); i++){
            for(int j = i+1; j < strs.size(); j++){
                if(isSimilar(strs[i], strs[j])){
                    connect(i, j);
                }
            }
        }
        return comp;
    }
};