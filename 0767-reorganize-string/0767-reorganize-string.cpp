class Solution {
public:
    string reorganizeString(string S) {
        std::vector<int> hash(26, 0);
    for (int i = 0; i < S.length(); i++) {
        hash[S[i] - 'a']++;
    } 
    
    int max = 0, letter = 0;
    for (int i = 0; i < hash.size(); i++) {
        if (hash[i] > max) {
            max = hash[i];
            letter = i;
        }
    }
    
    if (max > (S.length() + 1) / 2) {
        return "";
    }
    
    std::vector<char> res(S.length(), 0);
    int idx = 0;
    while (hash[letter] > 0) {
        res[idx] = static_cast<char>(letter + 'a');
        idx += 2;
        hash[letter]--;
    }
    
    for (int i = 0; i < hash.size(); i++) {
        while (hash[i] > 0) {
            if (idx >= res.size()) {
                idx = 1;
            }
            res[idx] = static_cast<char>(i + 'a');
            idx += 2;
            hash[i]--;
        }
    }
    
    return std::string(res.begin(), res.end());

        
    }
};