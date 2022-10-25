class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord) return 0;
        queue<pair<string, int>> q;
        set<string> st(wordList.begin() , wordList.end());
        st.erase(beginWord);
        q.push({beginWord, 1});
        while(!q.empty()){
            string cur = q.front().first;
            int seq= q.front().second;
            q.pop();
            for(int i =0 ; i< cur.size() ; i++){
                char org = cur[i];
                for(int j =0; j < 26; j++){
                    cur[i] = 'a' + j;
                    if(st.find(cur) != st.end()){
                        st.erase(cur);
                        if(cur == endWord) return seq + 1;
                        q.push({ cur ,seq+1});
                    }
                }
                cur[i] = org;
            }
        }
        return 0;
        
    }
};