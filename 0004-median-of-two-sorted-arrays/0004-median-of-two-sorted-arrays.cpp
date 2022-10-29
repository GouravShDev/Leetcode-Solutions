class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> smallVec = nums1.size() < nums2.size() ? nums1 : nums2;
        vector<int> largeVec = smallVec != nums1 ? nums1 : nums2;
        // vector<int> smallVec = nums1;
        // vector<int> largeVec = nums2;
        int smallSize = smallVec.size();
        int largeSize = largeVec.size();
        int totalSize = smallSize + largeSize;
        int start = 0;
        int end = smallVec.size();
        while(start <= end){
            int cutL = (start + end )/2;
            int cutR = (totalSize)/2 - cutL;
            int l1 = cutL == 0 ? INT_MIN : smallVec[cutL-1];
            int l2 = cutR == 0 ? INT_MIN : largeVec[cutR-1];
            int r1 = cutL == smallSize ? INT_MAX : smallVec[cutL];
            int r2 = cutR == largeSize ? INT_MAX : largeVec[cutR];
            
            if(l1 <= r2 && l2 <= r1){
                if(totalSize & 1){
                    return min(r1, r2);
                }else{
                    return (max(l1, l2) + min(r1, r2))/2.0;
                }
            }else if(l1 > r2){
                end = cutL-1;
            }else{
                start=  cutL +1;
            }
        }
        return 0.0;
    }
};