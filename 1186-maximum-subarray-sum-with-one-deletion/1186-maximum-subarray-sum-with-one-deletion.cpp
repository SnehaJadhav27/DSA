class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        int oneDelete=INT_MIN;
        int noDelete=arr[0];
        int ans=arr[0];
        for(int i=1;i<n;i++){
            int previous_oneDelete=oneDelete;
            int previous_noDelete=noDelete;
            noDelete=max(arr[i],previous_noDelete+arr[i]);
            if(previous_oneDelete==INT_MIN){
                oneDelete=previous_noDelete;
            }
            else{
                oneDelete=max(previous_noDelete,previous_oneDelete+arr[i]);
            }
            ans=max(ans,max(noDelete,oneDelete));
        }
        return ans;
    }
};