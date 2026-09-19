class Solution {
public:
    string reorganizeString(string s) {

        unordered_map<char, int> freq;

        
        for(auto ch : s) {
            freq[ch]++;
        }

        
        priority_queue<pair<int, char>> pq;

        for(auto ch : freq) {
            pq.push({ch.second, ch.first});
        }

        string ans = "";

        while(!pq.empty()) {

            auto first = pq.top();
            pq.pop();

            if(!ans.empty() && ans.back() == first.second) {

                
                if(pq.empty()) {
                    return "";
                }

                auto second = pq.top();
                pq.pop();

                ans += second.second;
                second.first--;

                if(second.first > 0) {
                    pq.push(second);
                }

                
                pq.push(first);
            }

            else {
                ans += first.second;
                first.first--;

                if(first.first > 0) {
                    pq.push(first);
                }
            }
        }

        return ans;
    }
};