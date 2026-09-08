class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for (auto& w : words) mp[w]++;

       
        auto cmp = [](pair<int,string>& a, pair<int,string>& b) {
            if (a.first != b.first)
                return a.first > b.first;
            return a.second < b.second; 
        };

        priority_queue<pair<int,string>, vector<pair<int,string>>, decltype(cmp)> pq(cmp);

        for (auto& i : mp) {
            pq.push({i.second, i.first});
            if (pq.size() > k) pq.pop();
        }

        vector<string> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};