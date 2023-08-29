class Solution {
public:
    int bestClosingTime(string customers) {
        int yCount = 0;
        for(int i = customers.size()-1; i >=0 ; i--){
            if(customers[i] == 'Y') yCount++;
        }
        int nCount = 0;
        int ans = customers.size();
        int curMnCount = customers.size()  - yCount;
        // cout<<curMnCount;
        for(int i = 0; i < customers.size(); i++){
            if((yCount + nCount) <= curMnCount ){
                if(yCount + nCount == curMnCount){
                    ans = min(ans, i);
                }else{
                    
                ans = i;
                }
                curMnCount = yCount + nCount;
            }
              if(customers[i] == 'Y'){
                yCount--;
            }
            if(customers[i] == 'N'){
                nCount++;
            }
           
        }
        return ans;
    }
};