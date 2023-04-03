class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0; 
        int j = people.size()-1;
        int ans = 0;
        while(i <= j){
            int sum = people[i] + people[j];
            if(sum <= limit){
                i++;
                j--;
            }else{
                j--;
            }
            ans++;
        }
        return ans;
    }
};