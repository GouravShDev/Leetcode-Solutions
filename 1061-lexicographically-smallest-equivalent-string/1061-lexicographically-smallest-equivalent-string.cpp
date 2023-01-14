class Solution {
public:
    vector<int> parent;
    int find(int u){
        if(parent[u] == u){
            return u;
        }
        return parent[u] = find(parent[u]);
    }
    void connect(int u , int v){
        u = find(u);
        v = find(v);
        if(u < v){
            parent[v] = u;
        }else{
            parent[u] = v;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);
        iota(parent.begin() , parent.end(),0);
        for(int i =0 ;i < s1.size() ; i++){
            connect(s1[i]-'a', s2[i]-'a');
        }
        string ans = baseStr;
        for(int i = 0;i < ans.size();i++){
        ans[i] = find(ans[i]-'a')+ 'a';
        }
        return ans;
    }
};