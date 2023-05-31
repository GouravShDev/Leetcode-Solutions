class UndergroundSystem {
public:
    map<int,pair<string,int>> mp; 
    map<string, pair<int,int>> mp2;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        int timeTaken = t - mp[id].second;
        string key = mp[id].first + "->" + stationName;
        mp2[key] = mp2.count(key) ? make_pair(mp2[key].first + timeTaken, mp2[key].second + 1) : make_pair(timeTaken, 1);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + "->" + endStation;
        return (double)( (double) mp2[key].first /  (double) mp2[key].second);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */