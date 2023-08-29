class Solution {
public:
    int bestClosingTime(string customers) {
        vector<int> pref(customers.size() + 1);
        for(int i = 1; i< customers.size()+1;i++){
            pref[i] = ((customers[i-1] == 'N') ? 1 : 0) + pref[i-1];
           
        }
        int ans = customers.size();
        int curMin = pref[customers.size()];
        int count = 0;
        for(int i = customers.size()-1; i >= 0 ; i--){
            if(customers[i] == 'Y') count++;
            int penalty = count + pref[i];
            
             //   cout<<curMin<<endl;
            if(penalty <= curMin){
                curMin = penalty;
                ans = i;
            }
        }
        return ans;
    }
};