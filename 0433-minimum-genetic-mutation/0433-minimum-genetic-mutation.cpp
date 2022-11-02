class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        set<string> bankSet(bank.begin() , bank.end());
        vector<char> possChar({'A', 'C', 'G', 'T'});
        queue<string> q;
        q.push(start);
        int mutation = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i =0 ;i < size; i++){
                string s = q.front();
                q.pop();
                if(s == end){
                    return mutation;
                }
                for(int j = 0; j  < s.size() ; j++){
                    char oldChar = s[j];
                    for(int k = 0 ; k < possChar.size() ; k++){
                        s[j] = possChar[k];
                        if(bankSet.find(s) != bankSet.end()){
                            bankSet.erase(s);
                            q.push(s);
                        }
                    }
                    s[j] = oldChar;
                }
            }
            mutation++;
        }
        return -1;
    }
};