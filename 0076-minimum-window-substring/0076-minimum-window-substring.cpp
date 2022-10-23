class Solution
{
    public:
        string minWindow(string s, string t)
        {
            vector<int> curMp(256);
            for (auto &ch: t)
            {
                curMp[ch]++;
            }
            int start = 0;
            int end = INT_MAX;
            int counter = 0;
            int i = 0;
            for (int j = 0; j < s.size(); j++)
            {
                if (curMp[s[j]] > 0) counter++;
                curMp[s[j]]--;

                while (counter == t.size())
                {
                    if (end - start > j - i)
                    {
                        start = i;
                        end = j;
                    }

                    if (curMp[s[i]] == 0)
                    {
                        counter--;
                    }
                    curMp[s[i]]++;
                    i++;
                }
            }
            return end != INT_MAX ? s.substr(start, end - start + 1) : "";
        }
};