//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    void precompute()
    {
        // Code Here
    }
    int count(long long num){
        int c = 0;
        while(num){
            if(num & 1) c++;
            num /= 2;
        }
        return c;
    }
    long long solve(long long l, long long r){
        long long ans = 0;
        long long cur = 0;
        set<long long> st;
        for(int i =0 ; i < 64 ; i++){
            cur |= (long(1) << i);
            for(int j = i+1; j < 64 ; j++){
                cur |= (long(1) << j);
                for(int k = j+1; k < 64 ; k++){
                    cur |= (long(1) << k);
                    
                    if(cur >= l && cur <= r && count(cur) == 3){
                        st.insert(cur);
                        // cout<<cur<<endl;
                        ans++;
                    }
                    cur ^= (long(1) << k);
                }
                cur ^= (long(1) << j);
            }
            cur ^= (long(1) << i);
        }
        return ans;
    }
    
};



//{ Driver Code Starts.

int main()
{
    int t;
    Solution ob;
    ob.precompute();
    cin>>t;
    while(t--)
    {
        long long l,r;
        cin>>l>>r;
        cout << ob.solve(l, r) << endl; 
    }
    return 0;
}
// } Driver Code Ends