class Solution {
public:
    void solve(vector<int>& nums,vector<int>& ans,vector<vector<int>>& res,vector<int>& freq,int n){
        if(ans.size()==n){
            res.push_back(ans);
            return;
        }
        for(int i=0;i<n;i++){
            if(!freq[i]){
                freq[i]=1;
                ans.push_back(nums[i]);
                solve(nums,ans,res,freq,n);
                freq[i]=0;
                ans.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> res;
        int n=nums.size();
        vector<int> freq(n,0);
        solve(nums,ans,res,freq,n);
        return res;
    }
};
