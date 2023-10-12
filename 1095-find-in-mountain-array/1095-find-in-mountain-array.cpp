/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        // vector<int> cache(n , -1);
        int start = 0;
        int end = n-1;
        int peak = -1;
        while(start <= end){
            int mid = start + (end - start)/2;
            // int prev= 0;
            // if(mid != 0){
            //    prev = mountainArr.get(mid-1)
            // }
            if(mid == 0 || mountainArr.get(mid-1) < mountainArr.get(mid)){
                peak = mid;
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        
        start = 0;
        end = peak;
        while(start <=end){
            int mid = start + (end - start)/2;
            int cur = mountainArr.get(mid);
            if(cur == target){
                return mid;
            }
            if(cur < target){
                start = mid + 1;
            }else{
                end = mid-1;
            }
        }
        start = peak+1;
        end = n-1;
        while(start <=end){
            int mid = start + (end- start)/2;
            int cur = mountainArr.get(mid);
            if(cur == target){
                return mid;
            }
            if(cur < target){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return -1;
    }
};