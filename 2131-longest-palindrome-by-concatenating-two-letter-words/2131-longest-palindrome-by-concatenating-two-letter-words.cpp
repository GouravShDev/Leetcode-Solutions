class Solution
{
    public:
        int longestPalindrome(vector<string> &words)
        {
            map<string, int> mp;
            for (auto &word: words)
            {
                mp[word]++;
            }
            int ans = 0;
            for (auto &word: words)
            {
                string revW = word;
                reverse(revW.begin(), revW.end());
                if (mp.find(revW) != mp.end() && mp[revW] > 0 && mp[word] > 0 && revW != word)
                {
                    int mn = min(mp[word], mp[revW]);
                    mp[word] -= mn;
                    mp[revW] -= mn;
                    ans += 4 * mn;
                }
                if (revW == word && mp[word] > 1)
                {
                    int m = mp[word];
                    if(m & 1) m--;
                    mp[word] -= m;
                    ans += 2 * m;
                }
                
            }
            for (auto &it: mp)
                {
                //if(it.second ==0)continue;
                
                    string revW = it.first;
                    reverse(revW.begin(), revW.end());
                    if (it.first == revW&& it.second == 1)
                    {
                        ans += 2;
                        break;
                    }
                }
            return ans;
        }
};