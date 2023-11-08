class Solution {
public:
    bool isReachableAtTime(int x1, int y1, int x2, int y2, int t) {
        if(x1 == x2 && y1 == y2 ) return t!= 1;
        return max(abs(y2 - y1) , abs(x2 - x1)) <= t;
    }
};