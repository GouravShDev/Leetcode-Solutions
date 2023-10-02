class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice = 0;
        int bob = 0;
        int consA = 0;
        int consB =0 ;
        for(int i = 0 ;i< colors.size() ;i++){
            if(colors[i] == 'A'){
                if(consB > 2) bob += (consB - 2);
                consB = 0;
                consA++;
            }else{
                if(consA > 2) alice += (consA - 2);
                consA =0 ;
                consB++;
            }
        }
        
                if(consB > 2) bob += (consB - 2);
                if(consA > 2) alice += (consA - 2);
        // cout<<alice <<" " << bob;
        return alice > bob;
    }
};