class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        queue<int> q;
        for(int i =0 ; i< seats.size() ; i++){
            if(seats[i] == 1) q.push(i);
        }
        int dist = 0;
        while(!q.empty()){
            int size = q.size();
            dist++;
            for(int  i = 0 ; i < size ; i++){
                int seat = q.front();
                q.pop();
                if(seat - 1 >= 0 && seats[seat-1] == 0){
                    seats[seat-1] = dist;
                    q.push(seat-1);
                }
                if(seat + 1 < seats.size() && seats[seat+1] == 0){
                    seats[seat+1] = dist;
                    q.push(seat+1);
                }
            }
        }
        int ans = *max_element(seats.begin(), seats.end());
        return ans;
    }
};