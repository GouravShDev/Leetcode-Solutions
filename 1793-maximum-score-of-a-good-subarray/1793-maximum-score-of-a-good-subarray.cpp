class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int ans = nums[k];
        int i = k ;
        int j = k;
        int mn = nums[k];
        while(i >= 0 && j < nums.size()){
            int index;
            if(i > 0 && j < nums.size()-1){
                if(nums[i-1] < nums[j+1]){
                   
                    j++;
                     index = j;
                }else{
            
                    i--;
                            index = i;
                }
            }else if(i > 0){

                i--;
                                index = i;
            }else{
 
                j++;
                               index = j;
            }
            if(i < 0 || j == nums.size()) break;
            mn = min(mn, nums[index]);
            //cout<<mn<<endl;
            ans = max(ans, mn * (j - i + 1));
        }
        return ans;
    }
};