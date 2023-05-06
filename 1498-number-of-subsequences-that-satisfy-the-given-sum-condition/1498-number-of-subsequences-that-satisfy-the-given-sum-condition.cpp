class Solution {
public:
    
    
 
/* Iterative Function to calculate (x^y)%p in O(log y) */
int power(long long x,  int y, int p)
{
    int res = 1;     // Initialize result
   // cout<<x<<" "<<y<<" "<< p <<endl;
 if(y < 0) return 0;
    x = x % p; // Update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; //= In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    //cout<<res<<endl;
    return res;
}
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int mod = 1e9 + 7;
        int ans = 0;
        for(int i = 0 ;i < nums.size() ;i++){
            int count = upper_bound(nums.begin() + i , nums.end(), target - nums[i]) - (nums.begin() + i);
            //cout<<count<<" ";
            ans= (ans + power(2, count-1,mod )) % mod;
            
        }
        // cout<<endl;
        return ans;
        
    }
};