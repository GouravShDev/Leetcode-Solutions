class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() < 3) return points.size();
        int mx= 0;
        for(int i =0 ;i < points.size() ;i ++){
            for(int j = i+1; j < points.size() ; j++){
                int cur = 2;
                for(int k = 0;  k < points.size(); k++){
                    // (j2-i2)/ (j1 - i1) == (k2 - i2) / (k1 - i1);
                    if(k == i || k == j) continue;
                    int curSlope = (points[i][0] - points[k][0]) * (points[j][1] - points[i][1]);
                    int slope = (points[i][1] - points[k][1]) * (points[j][0] - points[i][0]);
                    if(curSlope == slope){
                        cur++;
                    }
                }
                mx = max(mx, cur);
            }
        }
        return mx;
    }
};