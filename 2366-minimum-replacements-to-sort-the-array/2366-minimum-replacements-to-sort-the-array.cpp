class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long n = nums.size(), x = 1e9, res = 0, k;
        for (int i = n - 1; i >= 0; --i) {
            k = (nums[i] + x - 1) / x;
            x = nums[i] / k;
            res += k - 1;
        }
        return res;
    }
};