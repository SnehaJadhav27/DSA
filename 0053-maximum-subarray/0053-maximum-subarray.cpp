class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int best_ending=nums[0];
        int result=nums[0];
        for(int i=1;i<n;i++){
            int v1=best_ending+nums[i];
            int v2=nums[i];
            best_ending=max(v1,v2);
            result=max(best_ending,result);
        }
        return result;
        
    }
};