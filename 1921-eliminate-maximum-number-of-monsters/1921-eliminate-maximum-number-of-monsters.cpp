class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> time;
        for(int i = 0; i < dist.size(); i++){
            time.push_back(ceil((double) dist[i]  / speed[i]));
        }
        sort(time.begin() , time.end());
        int count = 1;
        for(int i = 1 ;i < time.size() ;i++){
            if(time[i] <= count){ 
                break;
            }
            count++;
        }
        return count;
    }
};

/*
 [3,5,7,4,5]
 [2,3,6,3,2]
 
 t = 1
 dist = [X, 2, 1, 1, 3]
 
 t = 2
 dist = []
 
 
*/