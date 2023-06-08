class Solution {
public:
     void nextPermuation(vector<int> &perm){
        int index = -1;
        for(int i = perm.size()-2;  i >= 0; i--){
            if(perm[i] < perm[i+1]){
                index = i;
                break;
            }
        }
        int smallValIndex = index;
        for(int i = perm.size()-1; index != -1 && i > index;i--){
            if(perm[index] < perm[i]){
                smallValIndex= i;
                break;
            }
        }
        if(index == -1){
            reverse(perm.begin(), perm.end());
            return;
        }
        swap(perm[index], perm[smallValIndex]);
        reverse(perm.begin() + index +1, perm.end());
    }
    void nextPermutation(vector<int>& nums) {
        return nextPermuation(nums);
    }
};