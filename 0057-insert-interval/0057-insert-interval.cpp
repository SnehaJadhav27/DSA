class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int n = intervals.size();

        vector<vector<int>> res;

        bool inserted = false;

        // Step 1: Insert newInterval at correct position
        for(int i = 0; i < n; i++) {

            if(!inserted && intervals[i][0] >= newInterval[0]) {
                res.push_back(newInterval);
                inserted = true;
            }

            res.push_back(intervals[i]);
        }

        // If newInterval is the largest interval
        if(!inserted) {
            res.push_back(newInterval);
        }

        // Step 2: Merge intervals
        vector<vector<int>> ans;

        int start1 = res[0][0];
        int end1 = res[0][1];

        for(int i = 1; i < res.size(); i++) {

            int start2 = res[i][0];
            int end2 = res[i][1];

            if(end1 >= start2) {
                // Overlapping
                end1 = max(end1, end2);
            }
            else {
                // No overlap
                ans.push_back({start1, end1});

                start1 = start2;
                end1 = end2;
            }
        }

        // Add last interval
        ans.push_back({start1, end1});

        return ans;
    }
};