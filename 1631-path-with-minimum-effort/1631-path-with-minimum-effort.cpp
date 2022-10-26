class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int,int> >, vector<pair<int, pair<int,int> >>, greater<pair<int, pair<int,int> >>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>> efforts(heights.size() , vector<int>(heights[0].size(), 1e8));
        int n = heights.size();
        int m = heights[0].size();
        efforts[0][0] =0;
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        while(!pq.empty()){
            auto curEffort = pq.top().first;
            auto row = pq.top().second.first;
            auto col = pq.top().second.second;
            pq.pop();
            for(int i =0 ;i < 4; i++){
                int newRow= row+ dx[i];
                int newCol = col + dy[i];
                if(newRow < 0 || newRow >= n || newCol < 0 || newCol >= m) continue;
                int effort = max(abs(heights[newRow][newCol]- heights[row][col]), curEffort);
                if( effort  < efforts[newRow][newCol]){
                    efforts[newRow][newCol] = effort;
                    pq.push({efforts[newRow][newCol], {newRow, newCol}});
                }
            }
        }
        return efforts[n-1][m-1];
    }
};