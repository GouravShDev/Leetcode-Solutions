class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans = "";
        vector<int> freq(26);
        vector<bool> visited(26);
        for(auto &ch : s) freq[ch-'a']++;
        
        for(auto &ch  : s){
            while(!ans.empty() && ans.back() >= ch && freq[ans.back()-'a'] > 0 && !visited[ch-'a']){
                visited[ans.back()-'a'] = 0;
                ans.pop_back();
            }
            if(!visited[ch-'a']){
                ans.push_back(ch);
                visited[ch-'a']= 1;
            }
            freq[ch-'a']--;
        }
        return ans;
    }
};