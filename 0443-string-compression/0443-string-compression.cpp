class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() <1) return 0;
        int i = 0;
        char lastOcc = chars[0];
        int count = 1;
        for(int j = 1; j < chars.size() ; j++){
            if(chars[j] == lastOcc){
                count++;
            }else{
                chars[i++] = lastOcc;
                if(count > 1){
                    string cStr = to_string(count);
                    for(int ind =0 ;ind < cStr.size() ; ind++){
                        chars[i++] = cStr[ind];
                    }
                }
                lastOcc = chars[j];
                count = 1;
            }
        }
        
        chars[i++] = lastOcc;
        if(count > 1){
            string cStr = to_string(count);
            for(int ind =0 ;ind < cStr.size() ; ind++){
                chars[i++] = cStr[ind];
            }
        }
        count = 1;
        return i;
    }
};