class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int m1 = -1;
        int m2 = -1;
        int f1 = 0;
        int f2 = 0;
        for(int num : nums){
            if(num == m1) f1++;
            else if(num == m2) f2++;
            else if(f1 == 0){
                m1 = num;
                f1 = 1;
            }else if (f2 == 0){
                m2 = num;
                f2 = 1;
            }else{
                f1--;
                f2--;
            }
        }
        f1 = 0;
        f2 = 0;
        for(int num : nums){
            if(num == m1) f1++;
            else if(num == m2) f2++;
        }
        cout<<m1 << m2;
        if(f1 > nums.size() / 3){
            ans.push_back(m1);
        }
        if(f2 > nums.size() / 3){
            ans.push_back(m2);
        }
        return ans;
    }
};