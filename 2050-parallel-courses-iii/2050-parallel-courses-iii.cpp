class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
                vector<vector<int>>adjList(n+1);

        vector<int>inDegrees(n+1,0);
        vector<int>timeTaken(n+1,0);

        // making adjList and storing inDegrees
        for(int i=0;i<relations.size();++i){
            int startNode=relations[i][0];
            int endNode=relations[i][1];
            
            inDegrees[endNode]++;
            adjList[startNode].push_back(endNode);
        }

        // pushing 0 inDegrees in queue
        queue<int>q;

        for(int i=1;i<inDegrees.size();++i){
            if(!inDegrees[i])
                q.push(i);
        }

        int maxmTime=0;
        while(!q.empty()){
            int currNode=q.front();
            q.pop();

            // calculating maximum time before popping off
            int currTime=timeTaken[currNode]+time[currNode-1];

            maxmTime=max(maxmTime,currTime);
            
            for(auto adj:adjList[currNode]){
                inDegrees[adj]--;
                
                // calculating time for adj
                timeTaken[adj]=max(timeTaken[adj],timeTaken[currNode]+time[currNode-1]);
 
                if(!inDegrees[adj]) q.push(adj);
            }
        }

        return maxmTime;

    }
};