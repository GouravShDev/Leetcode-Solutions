class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int areaSq1 = (ax2- ax1) * (ay2- ay1);
        int areaSq2 = (bx2 - bx1) * (by2 - by1);
        int left = max(ax1, bx1);
        int right = min(ax2, bx2);
        int top = min(ay2, by2);
        int bottom = max(ay1, by1);
        int overlap = 0 ;
        
        int x = (right - left) * (top - bottom);
        if(right > left && top > bottom){
            overlap =x;
        }
        return areaSq1 + areaSq2 - overlap;
        
    }
};