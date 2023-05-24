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
                pq.push({nums2[numWithIndex[i].second],numWithIndex[i].second});
            }else{
                ans = max(ans, sum * pq.top().first);
               sum -= nums1[pq.top().second];
                pq.pop();
                pq.push({nums2[numWithIndex[i].second],numWithIndex[i].second});
            }
            sum += numWithIndex[i].first;
        }
        if(pq.size() == k)    ans = max(ans, sum * pq.top().first);
        return ans;
    }
};