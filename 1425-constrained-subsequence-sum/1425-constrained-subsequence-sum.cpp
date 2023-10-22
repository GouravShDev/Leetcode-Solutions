class Solution {
public:
    int solve(vector<int> &nums, int index, int curK, bool isPicked, int k){
        if(index == nums.size()) return 0;
         if(curK == 0){
            return isPicked  ? 0 : INT_MIN;
        }
        int ans = INT_MIN;
       
        ans = max(ans, nums[index] + solve(nums, index+1, true,k, k));
        ans = max(ans, solve(nums, index+1, curK-1, isPicked ,k));
        return ans;
    }
    int constrainedSubsetSum(vector<int>& A, int k) {
    deque<int> q;
        int res = A[0];
        for (int i = 0; i < A.size(); ++i) {
            A[i] += q.size() ? q.front() : 0;
            res = max(res, A[i]);
            while (q.size() && A[i] > q.back())
                q.pop_back();
            if (A[i] > 0)
                q.push_back(A[i]);
            if (i >= k && q.size() && q.front() == A[i - k])
                q.pop_front();
        }
        return res;
    }
};