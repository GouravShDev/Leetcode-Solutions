class Solution {
public:
    void expand(int left, int right, string &s,  vector<vector<int>> &isPalindrome){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            isPalindrome[left][right] = 1;
            left--; right++;
        }
    }
    void solve(string &s, int start, int end, string cur, vector<string> &curStrs, vector<vector<int>> &isPal, vector<vector<string>> &ans){
        if(start == s.size()){
            ans.push_back(curStrs);
            return;
        }
        if(end >= s.size()) return;
        cur+= s[end];
        if(isPal[start][end]){
            curStrs.push_back(cur);
            solve(s, end+1, end+1, "", curStrs, isPal, ans );
            curStrs.pop_back();
        }
        solve(s, start , end+1, cur, curStrs, isPal, ans);
    }
    vector<vector<string>> partition(string s) {
        vector<vector<int>> isPalindrome(s.size() , vector<int>(s.size()));
        for(int i = 0; i < s.size(); i++){
            int start = i;
            int end = i;
            expand(start , end , s, isPalindrome);
             start = i;
             end = i+1;
            expand(start , end, s, isPalindrome);
        }
        vector<vector<string>> ans;
        vector<string> curStrs;
        solve(s , 0 , 0 , "" , curStrs, isPalindrome, ans);
        return ans;
    }
};