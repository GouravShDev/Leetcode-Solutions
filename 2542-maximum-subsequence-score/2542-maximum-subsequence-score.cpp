class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> numWithIndex;
        for(int i = 0 ; i < nums1.size(); i++){
            numWithIndex.push_back({nums1[i], i});
        }
        sort(numWithIndex.rbegin(), numWithIndex.rend());
        long long sum = 0;
        long long ans = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i = 0 ;i < nums2.size(); i++){
            if(pq.size() < k){
                
            sum += numWithIndex[i].first;
                pq.push({nums2[numWithIndex[i].second],numWithIndex[i].second});
            }
            if(pq.size() == k){
                
                ans = max(ans, sum * pq.top().first);
               sum -= nums1[pq.top().second];
                pq.pop();
            }
         //   sum += numWithIndex[i].first;
        }
        return ans;
    }
};