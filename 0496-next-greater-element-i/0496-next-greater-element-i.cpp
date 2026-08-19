class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        vector<int> res(n);
        res[n-1]=-1;
        stack<int> st;
        st.push(nums2[n-1]);
        unordered_map<int,int> mp;

        for(int i=n-2;i>=0;i--){
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            if(st.empty()){
                res[i]=-1;
            }
            else{
                res[i]=st.top();
            }
            st.push(nums2[i]);
            
        }

        for(int i=0;i<n;i++){
            mp[nums2[i]]=res[i];
        }

        vector<int> ans;
        for(int x:nums1){
            ans.push_back(mp[x]);
        }

        return ans;

    }
};