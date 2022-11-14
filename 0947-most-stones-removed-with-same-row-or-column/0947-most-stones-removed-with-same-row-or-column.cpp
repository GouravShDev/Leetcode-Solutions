class Solution {
    vector<int> parent;
    int cmp;
public:
    int findParent(int n){
        if(parent[n] == n){
            return n;
        }
        return parent[n] = findParent(parent[n]);
    }
    void unionn(int u , int v){
        u = findParent(u);
        v = findParent(v);
        if( u == v) return;
            parent[v] = u;  
        // cout<<u << " "<<v<<endl;
        cmp--;
    }
    int removeStones(vector<vector<int>>& stones) {
        int row = 0;
        int col = 0;
          for(auto &stone : stones){
            row = max(row, stone[0]);
            col = max(col , stone[1]);
        }
        parent.resize(row + col+2);
       int n = row +  col + 2;
        iota(parent.begin() , parent.end(), 0);
        set<int> st;
        set<int> st2;
        for(auto &stone : stones){
            unionn(stone[0], stone[1] + row+1 );
            st.insert(stone[0]);
            st.insert(stone[1] + row+1);
        }
        for(auto  s : st){
            st2.insert(findParent(s));
        }
        
        // cout<<cmp;
        return stones.size() -  st2.size();
    }
};