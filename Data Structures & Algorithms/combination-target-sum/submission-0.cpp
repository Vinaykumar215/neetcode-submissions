class Solution {
public:
    void solve(vector<int>& nums,int target,vector<int>& ans,vector<vector<int>>& res,int ind,int n){
        if(ind==n){
            if(target==0){
                res.push_back(ans);
            }
            return;
        }

        if(nums[ind]<=target){
            ans.push_back(nums[ind]);
            solve(nums,target-nums[ind],ans,res,ind,n);
            ans.pop_back();
        }
        solve(nums,target,ans,res,ind+1,n);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<vector<int>> res;
        solve(nums,target,ans,res,0,nums.size());
        return res;
    }
};
