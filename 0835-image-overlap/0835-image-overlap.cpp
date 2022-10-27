class Solution {
public:
    int countOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2, int xShift, int yShift){
        int n = img1.size();
        int count = 0;
        for(int i = xShift ;i < n ; i++){
            for(int j = yShift; j < n ; j++){
                count += (img1[i][j] * img2[i-xShift][j-yShift]);
            }
        }
        return count;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans = 0;
        int n = img1.size();
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < n ; j++){
                ans  = max(ans, countOverlap(img1, img2, i , j));
                ans = max(ans, countOverlap(img2, img1, i , j));
                
            }
        }
        reverse(img1.begin(), img1.end());
        reverse(img2.begin(), img2.end());
         for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < n ; j++){
                ans  = max(ans, countOverlap(img1, img2, i , j));
                ans = max(ans, countOverlap(img2, img1, i , j));
                
            }
        }
        return ans;
    }
};