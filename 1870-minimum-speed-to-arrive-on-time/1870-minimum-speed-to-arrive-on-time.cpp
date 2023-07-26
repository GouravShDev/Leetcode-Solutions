class Solution {
public:  double timeTaken(vector<int>&dist, int speed){
      double ans = 0;
      // we take ceil of all train times, leaving last time
      // because need need to wait after all trains leaving the last one
      // so here ceil will round off the time to the next integer, (i.e 1.5 -> 2)
      for(int i=0; i<dist.size(); ++i){
        // adding last train time in decimal values
        if(i == dist.size()-1) ans += (double)dist[i]/speed; 
        
        // adding train time after rounding off to next int
        else ans += ceil((double)dist[i]/speed);
      }
      return ans;
    }
  
    int minSpeedOnTime(vector<int>& dist, double hour) {
      // min speed can be 1, and max can be 10^7
      int left = 1, right = pow(10,7);
      int ans = -1;
      
      while(left <= right){
        // find mid of the search space of speed
        int mid = right - (right - left)/2;
        
        // what is time taken, if mid is the curr speed
        double time = timeTaken(dist, mid);
        
        // if time taken <= hour, then this speed can be answer
        // but we will try for less speed, maybe less is our answer
        if(time <= hour) {
          ans = mid;
          right = mid-1;
        }
        
        // speed was too less, so the time taken was much more
        // hence we need more speed so increment the lower bound
        else {
          left = mid+1;
        }
      }
      
      return ans;
    }
};