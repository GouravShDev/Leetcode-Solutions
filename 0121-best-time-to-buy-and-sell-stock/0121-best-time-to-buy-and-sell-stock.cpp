class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int mxProfit = INT_MIN; 
        int mn = INT_MAX;
        for(auto &price : prices){
            mn = min(mn , price);
            mxProfit = max(mxProfit, price - mn);
        }
        return mxProfit;
    }
};