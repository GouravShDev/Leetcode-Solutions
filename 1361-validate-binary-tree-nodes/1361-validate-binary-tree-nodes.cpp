class DisjointSet{
public:
    vector<int> parent;
    vector<int> sizes;
    int sz;
    DisjointSet(int n ){
        parent.resize(n);
        sizes.resize(n,1);
        sz = n;
        iota(parent.begin(), parent.end(),0);
    }
    int connect(int r , int c, int n ,int m, vector<vector<int>>& grid, bool connect = true){
        if(connect) grid[r][c] = 1;
        int del[] = {0, 1 ,0 , -1 , 0};
        int size = 1;
        set<int> temp;
        for(int index = 0; index < 4; index++){
            int newRow = r + del[index];
            int newCol = c + del[index+1];
            if(newRow < 0 || newCol < 0 || newRow >= n || newCol >= m || grid[newRow][newCol] == 0){
                continue;
            }
            int u = r*m + c;
            int v= newRow * m + newCol;
            
            if(connect)
                unionn(u, v);
            else
                temp.insert(findParent(v));
        }
        if(connect) return sizes[r*m+c];
        for(auto &v : temp){
            // cout<<v<<" "
            size += sizes[v];
        }
        return size;
    }
    void unionn(int u , int v){
        u = findParent(u);
        v = findParent(v);
        if(u == v) return;
        
        // if(sizes[u] > sizes[v]){
            sizes[v] += sizes[u];
            parent[u] = v;
        // }else{
            // sizes[u] += sizes[v];
            // parent[v] = u;
        // }
        
        sz--;
    }
    int findParent(int n){
        if(n == parent[n]){
            return n;
        }
        return parent[n] = findParent(parent[n]);
    }  
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        DisjointSet uf(n);
        for(int i = 0 ; i< n; i++){
            if(leftChild[i] != -1){
                if(leftChild[i]!= uf.findParent(leftChild[i]) || uf.findParent(leftChild[i]) == uf.findParent(i)) return false;
            }
            if(rightChild[i] != -1){
                if(rightChild[i] != uf.findParent(rightChild[i])  || uf.findParent(rightChild[i]) == uf.findParent(i)) return false;
            }
            if(leftChild[i] != -1 && rightChild[i] != -1 && uf.findParent(rightChild[i]) == uf.findParent(leftChild[i])) return false;
         if(leftChild[i] != -1)   uf.unionn(leftChild[i], i);
          if(rightChild[i] != -1)  uf.unionn(rightChild[i], i);
        }
        return uf.sz ==1;
    }
};