class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans = 0;
        int start = 0;
        int count = 0;
        for(int i = 0; i < answerKey.size();i++){
            if(answerKey[i] == 'F'){
                count++;
            }
            while(count > k && start < i){
                if(answerKey[start++] == 'F'){
                    count--;
                }
            }
            ans = max(ans, i - start+1);
        }
        start =0 ;
        count = 0;
        
        for(int i = 0; i < answerKey.size();i++){
            if(answerKey[i] == 'T'){
                count++;
            }
            while(count > k && start < i){
                if(answerKey[start++] == 'T'){
                    count--;
                }
            }
            ans = max(ans, i - start+1);
        }
        return ans;
    }
};