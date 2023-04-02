class Solution {
public:
    int binarySearch(vector<int> &poitions, int spell, long long success){
        int start =0 ;
        int end = poitions.size()-1;
        int ans = poitions.size();
        while(start <= end){
            int mid = start + (end -start)/2;
            if((1ll * poitions[mid] * spell) >= success){
                ans = mid;
                end = mid-1;
            }else{
                start = mid + 1;   
            }
        }
        return poitions.size() - ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(), potions.end());
        for(int i = 0; i < spells.size(); i++){
            ans.push_back(binarySearch(potions, spells[i], success));
        }
        return ans;
    }
};