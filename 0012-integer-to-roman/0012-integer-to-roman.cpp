class Solution {
public:
    string intToRoman(int num) {
        //"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
            map<int, string> mp = {
            {1, "I"},
            {4, "IV"},
            {5, "V"},
            {9, "IX"},
            {10, "X"},
            {40, "XL"},
            {50, "L"},
            {90, "XC"},
            {100, "C"},
            {400, "CD"},
            {500, "D"},
            {900, "CM"},
            {1000, "M"}
        };
        string ans = "";
        for(auto it = mp.rbegin(); it != mp.rend(); it++){
                //cout<<it->first<<endl;
                int x = num / it->first;
                while(x--){
                    ans+=it->second;
                }
                num %= it->first;
                //cout<<num<<endl;
        }
        return ans;
    }
};