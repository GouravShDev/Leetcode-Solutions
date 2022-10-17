class Solution
{
    public:
        int search(vector<int> &nums, int target)
        {
            if(nums.size() == 1) return target == nums[0] ? 0 : -1;
            int start = 0;
            int end = nums.size() - 1;
            int n = nums.size();
            while (start <= end)
            {
                int mid = (start + end) / 2;
                cout<<start <<" "<<end<<endl;
                if (nums[mid] == target)
                {
                    return mid;
                }
                else if (nums[mid] <= nums[n - 1])
                {
                    if (nums[mid] < target && target <= nums[n - 1])
                    {
                        start = mid+1;
                    }
                    else
                    {
                        end = mid-1;
                    }
                }
                else if (nums[0] <= nums[mid])
                {
                    if (nums[0] <= target && target < nums[mid])
                    {

                        end = mid-1;
                    }
                    else
                    {
                        start = mid+1;
                    }
                }
            }
            return -1;
        }
};