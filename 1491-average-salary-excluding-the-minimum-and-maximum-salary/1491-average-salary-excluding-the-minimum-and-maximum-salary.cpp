class Solution {
public:
    double average(vector<int>& salary) {
        double sum = 0;
        int mx = INT_MIN;
        int mn = INT_MAX;
        for(int i =0 ; i< salary.size(); i++){
           mn = min(salary[i], mn);
            mx= max(salary[i], mx);
            sum += salary[i];
        }
        return (sum - mx - mn)/ (double) (salary.size()-2);
    }
};