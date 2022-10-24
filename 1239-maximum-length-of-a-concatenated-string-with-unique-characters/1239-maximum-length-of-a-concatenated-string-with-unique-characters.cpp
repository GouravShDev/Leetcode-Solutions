class Solution
{
    public:
    int ans = 0;
        int solve(vector<string> &arr, vector<int> &getMaps, string cur, int mp, int index)
        {
            if (index == arr.size())
            {
                // cout << cur << endl;
                return cur.size();
            }

            ans = max((int) cur.size() , ans);
            for (int i = index + 1; i < arr.size(); i++)
            {
                if (getMaps[i] != -1 && (getMaps[i] &mp) == 0)
                {
                   	// cout<<i<<endl;
                    solve(arr, getMaps, cur + arr[i], getMaps[i] | mp, i);
                }
            }
            return ans;
        }
    vector<int> getMaps(vector<string> &strings)
    {
        vector<int> mps(strings.size());
        for (int i = 0; i < strings.size(); i++)
        {
            int mp = 0;
            for (auto &ch: strings[i])
            {
                int mask = 1 << (ch - 'a');
                if ((mask & mp) > 0)
                {
                    mp = -1;
                    break;
                }
                mp |= mask;
            }
            mps[i] = mp;
        }
        return mps;
    }
    int maxLength(vector<string> &arr)
    {
        vector<int> mps = getMaps(arr);
        // int ans = 0;
        for(int i =0 ; i < arr.size(); i++){
            if(mps[i] != -1)
                solve(arr, mps, arr[i], mps[i], i);
        }
        return ans;
    }
};