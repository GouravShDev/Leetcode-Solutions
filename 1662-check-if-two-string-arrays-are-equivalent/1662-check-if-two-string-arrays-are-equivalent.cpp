class Solution
{
    public:
       	//[
       	// "ab",
       	// "c"
       	//]
        bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
        {
            int w1 = 0, w2 = 0;
            int j1 = 0, j2 = 0;
            while (w1 < word1.size() && w2 < word2.size())
            {
               
                if (word1[w1][j1] != word2[w2][j2])
                {
                   	// cout<<word1[w1][j1]<< " "<<word2[w2][j2];
                    return false;
                }
                j1++;
                j2++;
                 if (j1 == word1[w1].size())
                {
                    w1++;
                    j1 = 0;
                }
                if (j2 == word2[w2].size())
                {
                    w2++;
                    j2= 0;
                }
            }
            if(w1 < word1.size() || w2 < word2.size()) return false;
            return true;
        }
};