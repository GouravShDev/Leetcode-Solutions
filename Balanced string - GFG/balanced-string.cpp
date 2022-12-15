//{ Driver Code Starts
// Initial template for c++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++

class Solution {
  public:
  int sumOfDigits(int n){
      int sum = 0;
      while(n){
          sum += (n % 10);
          n/= 10;
      }
      return sum;
  }
    string BalancedString(int n) {
        string alpha = "";
        for(int i =0 ; i < 26; i++){
            alpha += ('a' + i);
        }
        // string revAlpha = string(alpha.rbegin() , alpha.rend());
        string ans = "";
        int N = n;
        while(N){
            while(N >= 26){
                ans+= alpha;
                N -= 26;
            }
            if(N % 2 == 0){
                    ans += alpha.substr(0, N/2);
                    ans += alpha.substr(26 - (N/2) );
                
            }else{
                int digitSum = sumOfDigits(n);
                //cout<<digitSum<<endl;
                if(digitSum % 2 == 0){
                    ans += alpha.substr(0, (N+1)/2);
                    ans += alpha.substr(26 - ((N-1)/2 ) );
                    
                }else{
                    ans += alpha.substr(0, (N-1)/2);
                    ans += alpha.substr(26 - ((N+1)/2 ) );
                }
            }
            N= 0;
        }
        return ans;
    }
};
// class Solution {
//   public:
  
//     string BalancedString(int N) {
       
//         int times = N / 26;
//         int nums = N % 26;
        
//         string temp = "abcdefghijklmnopqrstuvwxyz";
//         string ans = "";
        
//         while(times--) {
//             ans += temp;
//         }
        
//         if(nums % 2 == 0) {
//             // cout<<"even"<<endl;

//             ans += temp.substr(0, nums >> 1);
//             ans += temp.substr(26 - (nums >> 1));
//         }
//         else {
            
//             int sum = 0;
//             int n = N;
            
//             while(n) {
//                 sum += n%10;
//                 n /= 10;
//             }
//             cout<<N<<endl;
//             if(sum % 2 == 0) {
//                 // cout<<"odd even"<<endl;
                
//                 ans += temp.substr(0, (nums + 1) >> 1);
//                 ans += temp.substr(26 - ((nums - 1) >> 1));
//             }
//             else {
//                 // cout<<"odd odd"<<endl;
                
//                 ans += temp.substr(0, (nums - 1) >> 1);
//                 ans += temp.substr(26 - ((nums + 1) >> 1));
//             }
            
//         }
    
//         return ans;
//     }
    
// };


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.BalancedString(N) << endl;
    }
    return 0;
}

// } Driver Code Ends