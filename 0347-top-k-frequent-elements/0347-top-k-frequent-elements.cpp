class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        for( auto i : mp ){
            int element=i.first;
            int frequency=i.second;

            if(pq.size()<k){
                pq.push({frequency,element});
            }
            else if(frequency>pq.top().first){
                pq.pop();
                pq.push({frequency,element});
            }
        }

        vector<int>result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
        
    }
};