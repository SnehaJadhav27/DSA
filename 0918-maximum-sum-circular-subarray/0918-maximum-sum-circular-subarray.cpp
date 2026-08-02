class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int bestmax=nums[0];
        int curmax=nums[0];
        int curmin=nums[0];
        int bestmin=nums[0];
        int n=nums.size();
        int total=nums[0];
        int circular=nums[0];
        for(int i=1;i<n;i++){
            int v1=nums[i];
            int v2=curmax+nums[i];
            int v3=curmin+nums[i];
            curmax=max(v1,v2);
            bestmax=max(bestmax,curmax);
            curmin=min(v1,v3);
            bestmin=min(bestmin,curmin);
            total+=v1;
            
        }
        if(bestmax<0){
                return bestmax;
            }
        circular=total-bestmin;
        return max(circular,bestmax);
    }
};