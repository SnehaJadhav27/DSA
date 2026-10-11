class Solution {
public:
    void solve(int n, int idx, vector<int>& candidates, int target, int sum,
               vector<int>& tmp, vector<vector<int>>& result) {
        // Base case 1: valid combination
        if (sum == target) {
            result.push_back(tmp);
            return;
        }

        // Base case 2: no more stages
        if (idx == n) return;

        // Choice 1: take candidates[idx] (stay on same idx, reuse allowed)
        if (sum + candidates[idx] <= target) {
            tmp.push_back(candidates[idx]);
            solve(n, idx, candidates, target, sum + candidates[idx], tmp, result);
            tmp.pop_back();
        }

        // Choice 2: skip candidates[idx]
        solve(n, idx + 1, candidates, target, sum, tmp, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> tmp;
        vector<vector<int>> result;
        solve(n, 0, candidates, target, 0, tmp, result);
        return result;
    }
};