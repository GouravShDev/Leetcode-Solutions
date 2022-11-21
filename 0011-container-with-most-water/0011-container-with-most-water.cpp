class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int ans = 0;
        while(left < right){
            if(height[left] < height[right]){
                int area = (right - left) * height[left++];
                ans = max(ans , area);
            }else{
                int area = (right - left) * height[right--];
                ans = max(ans , area);
            }
        }
        return ans;
    }
};