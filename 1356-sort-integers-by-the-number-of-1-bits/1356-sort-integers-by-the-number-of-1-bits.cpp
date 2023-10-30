class Solution {
public:
    int count(int x){
        int ans  = 0;
        while(x){
            x &= (x-1);
        }
        return ans;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](auto &a , auto &b){
            
            auto count = [] (int x) -> int{
                int ans  = 0;
                while(x){
                    x &= (x-1);
                    ans++;
                }
                return ans;
            };
           int x = count(a);
           int y =  count(b);
           if(x == y) return a < b;
            return x <y ;
        });
        return arr;
    }
};