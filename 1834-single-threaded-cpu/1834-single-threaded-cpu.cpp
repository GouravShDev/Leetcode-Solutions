class Task{
    public:
    int id;
    int eqTime;
    int pTime;
    Task(int t_id, int e, int p){
        id = t_id;
        eqTime = e;
        pTime = p;
    }
};
struct compare{
    bool operator()(const Task &a, const Task &b){
        if(a.pTime == b.pTime){
            return a.id > b.id;
        }
        return a.pTime > b.pTime;
    }
};
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<Task, vector<Task > , compare > pq;
        int n = tasks.size();
        vector<Task> tsks;
        for(int i =0 ;i < n; i++){
            tsks.push_back(Task(i , tasks[i][0], tasks[i][1]));
        }
        sort(tsks.begin() , tsks.end(), [](auto a, auto b){
            return a.eqTime < b.eqTime;
        });
        // for(auto & ts : tsks){
            // cout<<ts.eqTime<<" ";
        // }
        int i = 0;
        long long curTime = 0;
        vector<int> ans(n);
        int k = 0;
        while(!pq.empty() || i < n){ 
            
            if(pq.empty()){
                curTime = max(tsks[i].eqTime * 1ll, curTime);
            }
            while(i < n && curTime >= tsks[i].eqTime){
                pq.push(tsks[i++]);
            }
           
            ans[k++] = pq.top().id;
            curTime += pq.top().pTime;
            // cout<<curTime<<" ";
            pq.pop();
        }
        return ans;
    }
};