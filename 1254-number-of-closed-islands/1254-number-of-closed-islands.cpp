class UnionFind
{
private:
    vector<int> id, rank;
    int cnt;
public:
    UnionFind(int cnt) : cnt(cnt)
    {
        id = vector<int>(cnt);
        rank = vector<int>(cnt, 0);
        for (int i = 0; i < cnt; ++i)
            id[i] = i;
    }
    int find(int p)
    {
        if (id[p] == p)
            return p;
        return id[p] = find(id[p]);
    }
    int getCount()
    {
        return cnt;
    }
    bool connected(int p, int q)
    {
        return find(p) == find(q);
    }
    void connect(int p, int q)
    {
        int i = find(p), j = find(q);
        if (i == j)
            return;
        if (rank[i] < rank[j])
        {
            id[i] = j;
        }
        else
        {
            id[j] = i;
            if (rank[i] == rank[j])
                rank[j]++;
        }
        --cnt;
    }
};
class Solution {
public:
     void connect(vector<vector<int>> &grid, int i1 , int j1 , int i2, int j2, int n , int m, UnionFind &uf){
        if(i1 < 0 || j1 < 0 || i1 >= n || j1 >= m || i2 < 0 || j2 < 0 || i2 >= n || j2 >= m || grid[i1][j1] != 0 || grid[i2][j2] != 0 )return;
        uf.connect(i1 * m + j1 , i2 * m + j2);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int zeros = 0;
        UnionFind uf(n * m + 1);
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            if(grid[i][0] == 0){
                uf.connect(i * m , n * m);
            }
            
            if(grid[i][m-1] == 0){
                uf.connect(i * m + m-1 , n *  m);
            }
        }
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[0][j] == 0){
                uf.connect(j , n * m);
            }
            if(grid[n-1][j] == 0){
                uf.connect( (n-1) * m + j , n * m);
            }
        }
        for(int i =0 ; i < grid.size();i++){
            for(int j = 0; j < grid[0].size() ;j++){ 
                if(grid[i][j] == 1) count++;
                connect(grid, i, j, i+1, j, n , m , uf);
                connect(grid, i, j, i, j+1, n , m , uf);
            }
        }
        return uf.getCount() - count -1 ;
        
    }
};