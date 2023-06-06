class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for(int i = 1 ; i< arr.size()-1; i++){
            int prevDif = arr[i] - arr[i-1];
            int nextDif = arr[i+1] - arr[i];
            if(nextDif != prevDif) return false;
        }
        return true;
    }
};