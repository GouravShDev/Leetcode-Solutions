class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int r = grid.size()-1;
        int c = 0;
        int ans = 0;
        while(r >= 0 && c < grid[0].size()){
            if(grid[r][c] >= 0){
                c++;
            }else{
                ans+= grid[0].size() - c;
                r--;
            }
        }
        return ans;
    }
};

/*

4 3 2 -1
3 2 1 -1
1 1 -1 -2

*/