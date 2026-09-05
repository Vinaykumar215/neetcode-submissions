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
        int next=ind+1;
        while(next < n && nums[next]==nums[ind]){
            next++;
        }
        solve(nums,ans,res,next,n);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> res;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        solve(nums,ans,res,0,n);
        return res;
    }
};
