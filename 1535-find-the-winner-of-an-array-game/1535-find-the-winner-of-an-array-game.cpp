class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int mx = *max_element(arr.begin(), arr.end());
        int c = arr[0];
        int count = 0;
        for(int i = 1 ;i < arr.size(); i++){
            if(c > arr[i]){
                count++;
                
            }else{
                count = 1;
                c = arr[i];
            }
            if(count == k || arr[i] == mx) return c;
        }
        return c;
    }
};

// 2 3 1 5