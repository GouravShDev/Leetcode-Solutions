class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start =0 ;
        int end = arr.size()-1;
        int ans = -1;
        while(start <= end){
            int mid = start + (end - start)/2;
            
            if(mid == 0 || arr[mid-1] < arr[mid]){
                ans = mid;
                start = mid + 1;
            }else{
                end = mid -1;
            }
        }
        return ans;
    }
};