class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int oneCount = 0;
        int zeroCount = 0;
        int ans = INT_MAX;
        int n = s.size();
        for(auto &it: s){
            if(it=='1'){
                oneCount++;
            }
        }
        ans = min(ans, oneCount);
        ans = min(ans, n - oneCount);
        for(int i = 0; i< s.size() ; i++){
            if(s[i] == '0'){
                zeroCount++;
            }
            
            
            ans = min(ans, (i+1 - zeroCount) + (n-i-1 - oneCount));
            if(s[i] == '1'){
                oneCount--;
            }
        }
        return ans;
    }
};