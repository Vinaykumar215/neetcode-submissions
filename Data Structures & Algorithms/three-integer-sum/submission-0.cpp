class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int l=n-1;
            while(j<l){
                
                long long sum=nums[i];
                sum+=nums[j]+nums[l];
                if(sum>0){
                    l--;
                }else if(sum<0){
                    j++;
                }else if(sum==0){
                    res.push_back({nums[i],nums[j],nums[l]});
                    j++;
                    l--;

                    while(j<l && nums[l]==nums[l+1]) l--;
                    while(j<l && nums[j]==nums[j-1]) j++;
                }

            }
        
        }
        return res;
    }
};
