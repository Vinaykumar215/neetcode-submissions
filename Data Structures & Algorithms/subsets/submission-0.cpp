class Solution {
public:
    void solve(vector<int>& nums,vector<int>& ans,vector<vector<int>>& res,int ind,int n){
        if(ind==n){
            res.push_back(ans);
            return;
        }
        ans.push_back(nums[ind]);
        solve(nums,ans,res,ind+1,n);
        ans.pop_back();
        solve(nums,ans,res,ind+1,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> res;
        solve(nums,ans,res,0,nums.size());
        return res;
    }
};
