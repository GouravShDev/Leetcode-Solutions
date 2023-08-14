//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int xorr = 0;
        for(auto &n : nums){
            xorr ^= n;
        }
        int num1 = xorr;
        int num2 = xorr;
        int lsb = 0;
        for(int i = 0 ; i< 32; i++){
            int mask = 1 << i;
            if((mask & xorr) > 0){
                lsb = i;
                break;
            }
        }
        for(auto &num : nums){
            int mask = 1 << lsb;
            if((num & mask) > 0){
                num1 ^= num;
            }else{
                num2 ^= num;
            }
        }
        int mn = min(num1, num2);
        int mx = max(num1, num2);
        return {mn, mx};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends