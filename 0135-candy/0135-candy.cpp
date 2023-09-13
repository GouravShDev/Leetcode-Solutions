class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = ratings.size();
        int i = 1;
        while(i < ratings.size()){
            while(i < ratings.size() && ratings[i-1] == ratings[i]) i++;
            
            int hill = 0;
            while(i < ratings.size() && ratings[i-1] < ratings[i]){     hill++;
                ans += hill;
           
                i++;
            }
            int valley = 0;
            while(i < ratings.size() && ratings[i-1] > ratings[i]){  valley++;
                ans += valley;
              
                i++;
            }
            ans -= min(valley, hill);
        }
        return ans;
    }
};