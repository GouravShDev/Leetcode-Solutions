class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       vector<int> ans;
        for(int i = 0 ;i < asteroids.size();i++){
                int finalAsteroid = asteroids[i];
                while(!ans.empty() && ((ans.back() > 0 && asteroids[i] < 0))){
                   if(abs(ans.back()) == abs(asteroids[i])){
                       ans.pop_back();
                       finalAsteroid = -1e6;
                       
                   }else if(abs(ans.back())> abs(asteroids[i])){
                        finalAsteroid = -1e6;
                    }else if(abs(asteroids[i]) > abs(ans.back())){
                       ans.pop_back();
                   }
                    if(finalAsteroid == -1e6) break;
                }
                if(finalAsteroid != -1e6) ans.push_back(finalAsteroid);
           
            
        }
        return ans;
    }
};