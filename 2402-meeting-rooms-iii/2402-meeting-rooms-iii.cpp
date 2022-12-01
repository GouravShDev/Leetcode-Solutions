class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<long long> meetingRooms(n);
        map<int,int> mp;
        
        for(auto &meet : meetings){
            long long start = meet[0];
            long long end = meet[1];
            int minMeet = 0;
            for(int i = 0; i < n; i++){
                if(meetingRooms[i] == 0 || meetingRooms[i] <= start){
                    minMeet = i;
                    break;
                }
                if(meetingRooms[minMeet] > meetingRooms[i]){
                    minMeet = i;
                }
            }
            mp[minMeet]++;
            if(meetingRooms[minMeet] < start) meetingRooms[minMeet] = start;
            meetingRooms[minMeet] += (end - start);
            
        }
        auto minMeet = mp.begin()->first;
        for(auto &it: mp){
            if(it.second > mp[minMeet]){
                minMeet = it.first;
            }
        }
        return minMeet;
    }
};