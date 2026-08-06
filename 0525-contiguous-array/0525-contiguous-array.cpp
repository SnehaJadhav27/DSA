class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int prefixsum=0;
        mp[0]=-1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                nums[i]=-1;
            }
        }

        for(int i=0;i<n;i++){
            prefixsum+=nums[i];
            if(mp.find(prefixsum)!=mp.end()){
                int length=i-mp[prefixsum];
                ans=max(ans,length);
            }
            else{
                mp[prefixsum]=i;
            }
            
        }
        return ans;
        
    }
};