class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int mx = -1;
        int a = -1;
        for(int i = 0 ; i < arr.size(); i++){
            if(arr[i] > mx){
                mx = arr[i];
                a = i;
            }
        }
        return a;
        int start =0 ;
        int end = arr.size()-1;
        int ans = -1;
        while(start <= end){
            int mid = start + (end - start)/2;
            
            if(arr[0] < arr[mid]){
                if(arr[mid] < arr[arr.size()-1]){
                   ans= mid;
                    start = mid + 1;
                }else{
                    
                }
            }else{
                end = mid-1;
            }
        }
        return ans;
    }
};