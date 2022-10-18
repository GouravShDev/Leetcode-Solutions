class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)  return "1";
        return solve(n);
    }
    
    
    string solve(int n) {
        string ans = "";
        if(n ==1) return "1";
        
        string number = solve(n-1);
        int freq = 1;
        auto lastElement = number[0];
        
        int i = 1;
        while(i < number.size()){
            if(lastElement == number[i]){
                freq++;
                
            }else{
                ans = ans + to_string(freq);
                ans+= lastElement;
                freq = 1;
                lastElement = number[i];
            }
            i++;
        }
        
        //cout<<lastElement<<endl;
        ans = ans + to_string(freq) + lastElement;
        return ans;
    }
};